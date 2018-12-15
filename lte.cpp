void
PfFfMacScheduler::DoSchedUlTriggerReq (const struct FfMacSchedSapProvider::SchedUlTriggerReqParameters& params)
{
  NS_LOG_FUNCTION (this << " UL - Frame no. " << (params.m_sfnSf >> 4) << " subframe no. " << (0xF & params.m_sfnSf) << " size " << params.m_ulInfoList.size ());

  RefreshUlCqiMaps ();

// PIMRC-------------------
  std::vector <uint16_t>  active_users1;
  std::map <uint16_t,uint32_t>::iterator it;
  std::map <uint16_t, std::vector <uint16_t> > allocationMap;
  int nflows = 0;
  tti++;
  std::ofstream datafile;
  datafile.open("/home/nitish/Desktop/Result/LW-Sim-40.txt",std::ios_base::app);
  if( tti==1000 )
  {
	datafile<< "---------------DATA--------" << std::endl;
	 for(int y=1;y<=globalUsers;++y)
	  {
	    datafile<< y << " "<< totalData[y] << std::endl;
	  }
  }





//  double time = Simulator::Now().GetMilliSeconds();
//-----------------------------

  std::cout<<"\n-----------------------------TTI " << tti << "---------------------------" << std::endl;

  // Generate RBs map
  FfMacSchedSapUser::SchedUlConfigIndParameters ret;
  std::vector <bool> rbMap;
  uint16_t rbAllocatedNum = 0;
  std::set <uint16_t> rntiAllocated;
  std::vector <uint16_t> rbgAllocationMap;
  // update with RACH allocation map
  rbgAllocationMap = m_rachAllocationMap;

  //rbgAllocationMap.resize (m_cschedCellConfig.m_ulBandwidth, 0);
  m_rachAllocationMap.clear ();
  m_rachAllocationMap.resize (m_cschedCellConfig.m_ulBandwidth, 0);

  rbMap.resize (m_cschedCellConfig.m_ulBandwidth, false);
  // remove RACH allocation
  for (uint16_t i = 0; i < m_cschedCellConfig.m_ulBandwidth; i++)
    {
      if (rbgAllocationMap.at (i) != 0)
        {
          rbMap.at (i) = true;
          NS_LOG_DEBUG (this << " Allocated for RACH " << i);
        }
    }


  if (m_harqOn == false)
    {
      //   Process UL HARQ feedback

      for (uint16_t i = 0; i < params.m_ulInfoList.size (); i++)
        {
          if (params.m_ulInfoList.at (i).m_receptionStatus == UlInfoListElement_s::NotOk)
            {
              // retx correspondent block: retrieve the UL-DCI
              uint16_t rnti = params.m_ulInfoList.at (i).m_rnti;
              std::map <uint16_t, uint8_t>::iterator itProcId = m_ulHarqCurrentProcessId.find (rnti);
              if (itProcId == m_ulHarqCurrentProcessId.end ())
                {
                  NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << rnti);
                }
              uint8_t harqId = (uint8_t)((*itProcId).second - HARQ_PERIOD) % HARQ_PROC_NUM;
              NS_LOG_INFO (this << " UL-HARQ retx RNTI " << rnti << " harqId " << (uint16_t)harqId << " i " << i << " size "  << params.m_ulInfoList.size ());
              std::map <uint16_t, UlHarqProcessesDciBuffer_t>::iterator itHarq = m_ulHarqProcessesDciBuffer.find (rnti);
              if (itHarq == m_ulHarqProcessesDciBuffer.end ())
                {
                  NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << rnti);
                  continue;
                }
              UlDciListElement_s dci = (*itHarq).second.at (harqId);
              std::map <uint16_t, UlHarqProcessesStatus_t>::iterator itStat = m_ulHarqProcessesStatus.find (rnti);
              if (itStat == m_ulHarqProcessesStatus.end ())
                {
                  NS_LOG_ERROR ("No info find in HARQ buffer for UE (might change eNB) " << rnti);
                }
              if ((*itStat).second.at (harqId) >= 3)
                {
                  NS_LOG_INFO ("Max number of retransmissions reached (UL)-> drop process");
                  continue;
                }
              bool free = true;
              for (int j = dci.m_rbStart; j < dci.m_rbStart + dci.m_rbLen; j++)
                {
                  if (rbMap.at (j) == true)
                    {
                      free = false;
                      NS_LOG_INFO (this << " BUSY " << j);
                    }
                }
              if (free)
                {
                  // retx on the same RBs
                  for (int j = dci.m_rbStart; j < dci.m_rbStart + dci.m_rbLen; j++)
                    {
                      rbMap.at (j) = true;
                      rbgAllocationMap.at (j) = dci.m_rnti;
                      NS_LOG_INFO ("\tRB " << j);
                      rbAllocatedNum++;
                    }
                  NS_LOG_INFO (this << " Send retx in the same RBs " << (uint16_t)dci.m_rbStart << " to " << dci.m_rbStart + dci.m_rbLen << " RV " << (*itStat).second.at (harqId) + 1);
                }
              else
                {
                  NS_LOG_INFO ("Cannot allocate retx due to RACH allocations for UE " << rnti);
                  continue;
                }
              dci.m_ndi = 0;
              // Update HARQ buffers with new HarqId
              (*itStat).second.at ((*itProcId).second) = (*itStat).second.at (harqId) + 1;
              (*itStat).second.at (harqId) = 0;
              (*itHarq).second.at ((*itProcId).second) = dci;
              ret.m_dciList.push_back (dci);
              rntiAllocated.insert (dci.m_rnti);
            }
            else
            {
              NS_LOG_INFO (this << " HARQ-ACK feedback from RNTI " << params.m_ulInfoList.at (i).m_rnti);
            }
        }
    }


  for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
    {
      std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).first);
      // select UEs with queues not empty and not yet allocated for HARQ
      if (((*it).second > 0)&&(itRnti == rntiAllocated.end ()))
        {
          nflows++;
          active_users1.push_back ((*it).first);
          std::cout<<"SIZE of "<<(*it).first<<" is::::"<<(*it).second<<std::endl;

        }
    }

std::cout<<"\nTotal Active Users : "<< nflows<<std::endl;
  if (nflows == 0)
    {
      if (ret.m_dciList.size () > 0)
        {
          m_schedSapUser->SchedUlConfigInd (ret);
        }

      return;  // no flows to be scheduled
    }


  // Divide the remaining resources equally among the active users starting from the subsequent one served last scheduling trigger
  uint16_t rbPerFlow = (m_cschedCellConfig.m_ulBandwidth) / (nflows + rntiAllocated.size ());
  if (rbPerFlow < 3)
    {
      rbPerFlow = 3;  // at least 3 rbg per flow (till available resource) to ensure TxOpportunity >= 7 bytes
    }
  int rbAllocated = 0;

  int totalChunk = m_cschedCellConfig.m_ulBandwidth/rbPerFlow;
  std::cout<<"\nTotal Chunk : " << totalChunk << std::endl;
  std::cout<<"\n Bandwidth : " <<(int)m_cschedCellConfig.m_ulBandwidth << std::endl;
  //FfMacSchedSapUser::SchedUlConfigIndParameters ret;
  //std::vector <uint16_t> rbgAllocationMap;
  //~ for (int w = 0; w < m_cschedCellConfig.m_ulBandwidth; w++)
  //~ {
       //~ rbgAllocationMap.push_back(0);
  //~ }
    std::cout<<"\n rbgAllocationMap Size : " << rbgAllocationMap.size() << std::endl;

  std::map <uint16_t, pfsFlowPerf_t>::iterator itStats;

 // std::map< uint16_t, std::vector <PfRBG> > V;
  for(int i=0 ; i < totalChunk ; i++)
  {
	uint16_t bestuser;
	double rcqi=0.0;
    double rcqiMax = 0.0;
    std::vector <uint16_t>active_users=active_users1;
    double achievableRate = 0.0;

    //while(!active_users.empty()){
	//	uint16_t indexOfBestUser;
		//PfRBG tempRBG;
	for(uint16_t j=0; j < active_users.size() ;j++)
	{
//std::cout << "\t Active user at " << j << "is " << active_users.at(j) << std::endl;
	  rcqi=0.0;
	  achievableRate = 0.0;
	  double mcs=0.0;
	  double cqi=0.0;
	  std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueCqi.find (active_users.at(j));
	  if (itCqi == m_ueCqi.end ())
	  {
	  }
	  else
	  {
	    double minSinr = (*itCqi).second.at (rbAllocated);
	    if (minSinr == NO_SINR)
	   	{
		  minSinr = EstimateUlSinr (active_users.at(j), rbAllocated);
		}
		for (uint16_t k = rbAllocated; k < rbAllocated + rbPerFlow; k++)
		{
		    double sinr = (*itCqi).second.at (k);
		    if (sinr == NO_SINR)
		    {
		      sinr = EstimateUlSinr (active_users.at(j), k);
		    }
		    if ((*itCqi).second.at (k) < minSinr)
		    {
		      minSinr = (*itCqi).second.at (k);
		    }
		}
		double s = log2 ( 1 + (
				     std::pow (10, minSinr / 10 )  /
				     ( (-std::log (5.0 * 0.00005 )) / 1.5) ));
		cqi = m_amc->GetCqiFromSpectralEfficiency (s);
	  }
	     if (cqi == 0)
	     {
			 mcs = 0;

	     }
	     else
	     {
		     mcs = m_amc->GetMcsFromCqi (cqi);
	     }
	     itStats = m_flowStatsUl.find (active_users.at(j));
	     achievableRate += ((m_amc->GetTbSizeFromMcs (mcs, rbPerFlow) / 8) / 0.001);
	     rcqi = achievableRate / (*itStats).second.lastAveragedThroughput;

/*	     if(j==0)
	     {
		     rcqiMax = rcqi;
		     bestuser=active_users.at(j);
		     indexOfBestUser = j;
	     }
	    if(rcqi > rcqiMax)
	    {
		    bestuser=active_users.at(j);
		    indexOfBestUser = j;
		    rcqiMax = rcqi;
	    }*/
	    arr[j]=rcqi;
	    save[j]=j;
	}
	sort(0,active_users.size()-1,arr,save);
	for(j=0;j<active_users.size();j++)
	{
		int tmp_chunk_no;
        std::map <uint16_t, std::vector <uint16_t> >::iterator tmp_map = allocationMap.find(active_users.at(save[j]));
		if(tmp_map!=alocationMap.end())
		{
            tmp_chunk_no=(*tmp_map).second.back();
            if(i==tmp_chunk_no+1)
            {
                (*tmp_map).second.push_back(i);
            }
            else
            continue;
		}
		else
		{
			std::vector<uint16_t> v;
			v.push_back(i);
			allocationMap.insert(std::pair <uint16_t, std::vector <uint16_t> > (active_users.at(save[j]),v);
		}
	}
}


    std::map <uint16_t, std::vector <uint16_t> >::iterator tmp_map = allocationMap.begin();

    while (tmp_map != allocationMap.end ())
    {
	  int min=(*tmp_map).second.at(0);
	  int max=(*tmp_map).second.back();
	  
		for (uint16_t k = (min*rbPerFlow); k < ((max*rbPerFlow)+rbPerFlow); k++)
		{
			rbgAllocationMap[k]=(*tmp_map).first;
		}

	tmp_map++;
    }


std::cout<<"\n---------------After---------\n"<<std::endl;
       for(uint16_t i=0;i<rbgAllocationMap.size();++i)
       {
	   std::cout << "\t" << rbgAllocationMap.at(i);
       }
std::cout<<"\n---------------END---------\n"<<std::endl;

    std::cout<<"\n rbgAllocationMap Size : " << rbgAllocationMap.size() << std::endl;

uint16_t user,size,start;
start=0;
while(start<rbgAllocationMap.size())
{
    user=rbgAllocationMap.at(start);
    size=0;

    while( (start+size < rbgAllocationMap.size()) && (user == rbgAllocationMap.at(start+size)))
    {
	size++;
    }

			UlDciListElement_s uldci;
            uldci.m_rnti = user;
            uldci.m_rbStart = start;
			if(start+size == 100)
			uldci.m_rbLen = size-1;
			else
			uldci.m_rbLen = size;

            std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueCqi.find (user);
            int cqi = 0;

		std::cout<<"\nUE " << uldci.m_rnti << " startPRB " << (uint32_t)uldci.m_rbStart << " nPRB " << (uint32_t)uldci.m_rbLen << std::endl;
		if (itCqi == m_ueCqi.end ())
		{
			// no cqi info about this UE
			uldci.m_mcs = 0; // MCS 0 -> UL-AMC TBD
			NS_LOG_DEBUG (this << " UE does not have ULCQI " << user);
		}
              else
                {
                        // take the lowest CQI value (worst RB)
                        double minSinr = (*itCqi).second.at (uldci.m_rbStart);

                        for (uint16_t i = uldci.m_rbStart; i < uldci.m_rbStart + uldci.m_rbLen; i++)
                        {
                                if ((*itCqi).second.at (i) < minSinr)
                                {
                                        minSinr = (*itCqi).second.at (i);
                                }
                        }
                        // translate SINR -> cqi: WILD ACK: same as DL
                        double s = log2 ( 1 + (
                                 std::pow (10, minSinr / 10 )  /
                                 ( (-std::log (5.0 * 0.00005 )) / 1.5) ));


                        cqi = m_amc->GetCqiFromSpectralEfficiency (s);
                        if (cqi == 0)
                        {
                                //trial
                                uldci.m_mcs = 0;
                                // continue; // CQI == 0 means "out of range" (see table 7.2.3-1 of 36.213)
                        }
                        else
                        {
                                //trial
                                uldci.m_mcs = m_amc->GetMcsFromCqi (cqi);
				 NS_LOG_DEBUG (this << " UE " <<  (*it).first << " minsinr " << minSinr << " -> mcs " << (uint16_t)uldci.m_mcs);
                        }
		}

		uldci.m_tbSize = (m_amc->GetTbSizeFromMcs (uldci.m_mcs, uldci.m_rbLen) / 8);
	   //std::cout<<"User: "<<uldci.m_rnti<<"\t"<<"Data: "<<uldci.m_tbSize <<"rbNum: "<<uldci.m_rbStart<<"\n";
	    //~ if((nflows==nettotal)&&settb)
	    //~ {
		//~ datafile<< "---------------DATA--------" << std::endl;
	//~
		  //~ for(int y=1;y<=globalUsers;++y)
		  //~ {
		    //~ datafile<< y << " "<< totalData[y] << std::endl;
		    //~ totalData[y] = 0;
		  //~ }
		  //~
	    //~ }

	    for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
	    {
		if((*it).first == uldci.m_rnti)
		break;
	    }
	    if((*it).second > uldci.m_tbSize)
	    totalData[uldci.m_rnti ] +=  uldci.m_tbSize;
	    else
	    totalData[uldci.m_rnti ] +=  (*it).second;

	     noOfTimesUserSchedule[uldci.m_rnti]++;
		//totalData[uldci.m_rnti ] +=  uldci.m_tbSize;
//std::cout<<"UE " << uldci.m_rnti << " startPRB " << (uint32_t)uldci.m_rbStart << " nPRB " << (uint32_t)uldci.m_rbLen << " CQI " << cqi << " MCS " << (uint32_t)uldci.m_mcs << " TBsize " << uldci.m_tbSize <<std::endl;
//		std::cout << "USER: " << uldci.m_rnti << " TBSIZE: " << uldci.m_tbSize << std::endl;
		//NS_LOG_DEBUG (this << " EACH USER UE " << uldci.m_rnti << " startPRB " << (uint32_t)uldci.m_rbStart << " nPRB " << (uint32_t)uldci.m_rbLen << " CQI " << cqi << " MCS " << (uint32_t)uldci.m_mcs << " TBsize " << uldci.m_tbSize << " RbAlloc " << start);
                      UpdateUlRlcBufferInfo (uldci.m_rnti, uldci.m_tbSize);
                      uldci.m_ndi = 1;
                      uldci.m_cceIndex = 0;
                      uldci.m_aggrLevel = 1;
                      uldci.m_ueTxAntennaSelection = 3; // antenna selection OFF
                      uldci.m_hopping = false;
                      uldci.m_n2Dmrs = 0;
                      uldci.m_tpc = 0; // no power control
                      uldci.m_cqiRequest = false; // only period CQI at this stage
                      uldci.m_ulIndex = 0; // TDD parameter
                      uldci.m_dai = 1; // TDD parameter
                      uldci.m_freqHopping = 0;
                      uldci.m_pdcchPowerOffset = 0; // not used
                      ret.m_dciList.push_back (uldci);

                      itStats = m_flowStatsUl.find (uldci.m_rnti);
                      if (itStats != m_flowStatsUl.end ())
                        {
                          (*itStats).second.lastTtiBytesTrasmitted =  uldci.m_tbSize;
                //                     NS_LOG_DEBUG (this << " UE bytes txed " << (*it).second.lastTtiBytesTrasmitted);
                        }
                      else
                        {
                          NS_LOG_DEBUG (this << " No Stats for this allocated UE");
                        }
			 start=start+size;

}


    //~ if((nflows==nettotal)&&settb)
    //~ settb=false;
    //~ datafile.close();

//    std::cout << "\n BLOCK 5 " <<std::endl;

    for (itStats = m_flowStatsUl.begin (); itStats != m_flowStatsUl.end (); itStats++)
    {
      (*itStats).second.totalBytesTransmitted += (*itStats).second.lastTtiBytesTrasmitted;
      // update average throughput (see eq. 12.3 of Sec 12.3.1.2 of LTE – The UMTS Long Term Evolution, Ed Wiley)
      (*itStats).second.lastAveragedThroughput = ((1.0 - (1.0 / m_timeWindow)) * (*itStats).second.lastAveragedThroughput) + ((1.0 / m_timeWindow) * (double)((*itStats).second.lastTtiBytesTrasmitted / 0.001));
      //std::cout<<"User "<<(*itStats).first <<" : avg thr: "<<(*itStats).second.lastAveragedThroughput<<std::endl;
      //       NS_LOG_DEBUG (this << " UE tot bytes " << (*itStats).second.totalBytesTransmitted);
      //       NS_LOG_DEBUG (this << " UE avg thr " << (*itStats).second.lastAveragedThroughput);
      (*itStats).second.lastTtiBytesTrasmitted = 0;
    }

  m_allocationMaps.insert (std::pair <uint16_t, std::vector <uint16_t> > (params.m_sfnSf, rbgAllocationMap));
  m_schedSapUser->SchedUlConfigInd (ret);
  return;
}



void sort(int low,int high,int *arr,int *save)
{
	int k,ctr1=0,ctr2=0;
	int cnt=1;
	int temp;
	int p=(low+high)/2;
	int i=low,j=high;
while(1)
{
 if(cnt==1)
 {
		if(i<p)
		{
		if(arr[i]>arr[p])
		{
			temp=arr[i];
			arr[i]=arr[p];
			arr[p]=temp;
			
			temp=save[i];
			save[i]=save[p];
			save[p]=temp;
			
			p=i;
			cnt=0;
		}
		if(cnt==1)
		i++;
	    }
	    else
	    cnt=0;
}
else
	{
		if(j>p)
		{
		if(arr[j]<arr[p])
		{
			temp=arr[j];
			arr[j]=arr[p];
			arr[p]=temp;
			
			temp=save[j];
			save[j]=save[p];
			save[p]=temp;
			
			p=j;
			cnt=1;
		}
		if(cnt==0)
		j--;
		//if(!(j>p))
		//cnt=1;
	    }
	    else
	    cnt=1;
	}
	if(i==p && j==p)
	break;
}
for(k=low;k<p;k++)
{
	if(arr[k]>arr[k+1])
	{
		ctr1++;
		break;
	}
}
if(low!=p && ctr1!=0)
{
sort(low,p,arr,save);
}
for(k=p+1;k<high;k++)
{
	if(arr[k]>arr[k+1])
	{
		ctr2++;
		break;
	}
}

if((p+1!=high)&& ctr2!=0)
{
sort(p+1,high,arr,save);
}

return;
}
