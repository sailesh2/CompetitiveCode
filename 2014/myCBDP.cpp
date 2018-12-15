
/*******************************************************************************************************/

int countTTI=0;
int waitedInQueue[57];
int totUsers = 0,tti=0,globalCounter=0,globalUsers=56;
uint64_t totalData[57];
int satisfiedUsers[57];			// keep list of unsatisfied users
double prevSatisfy[57];				// satisfied users in last tti
int noOfTimesUserSchedule[57];
int c2=10,c3=10,c4=10;



int nettotal;
bool change=false;
bool settb=false;

//int changedPriority[17];			//keep information of users after priority changed

uint8_t
qci2priority(uint8_t qci)
{
   switch (qci)
    {
    case 1:
      return 3;
    case 2:
      return 2;
    case 3:
      return 3;
    case 4:
      return 4;
    case 5:
      return 1;
    case 6:
      return 6;
    case 7:
      return 7;
    case 8:
      return 8;
    case 9:
      return 9;
    default:
      NS_FATAL_ERROR ("unknown QCI value " << qci);
      return 0;
    }

}

uint64_t
getSbr(uint8_t qci)
{
  switch (qci)
  {
    case 1:
      return 200000;
    case 2:
      return 300000;
    case 3:
      return 200000;
    case 4:
      return 200000;
    case 5:
      return 100000;
    case 6:
      return 100000;
    case 7:
      return 300000;
    case 8:
      return 100000;
    case 9:
      return 100000;
    case 10:
      return 100000;
    default:
      NS_FATAL_ERROR ("unknown QCI value " << qci);
      return 0;
    }
}






/*######################################################################################################3
######################################################################################################3
######################################################################################################3
#######################################################################################################3*/

void
PfFfMacScheduler::DoCschedLcConfigReq (const struct FfMacCschedSapProvider::CschedLcConfigReqParameters& params)
{
  //NS_LOG_FUNCTION (this << " New LC, rnti: "  << params.m_rnti);
  NS_LOG_INFO (this << " New LC, rnti: "  << params.m_rnti<<"\t"<<(uint16_t)(params.m_logicalChannelConfigList.back().m_qci));

  //XXX Added for m2msched //data regarding Logical channel is stored in params.
  bool isH2H;
  uint8_t qci,priority;
  qci = params.m_logicalChannelConfigList.back().m_qci;
  if(qci == 5){
    isH2H = false;
    priority  = qci2priority((qci));
    }
 else if(qci > 5){
    isH2H = false;
    priority  = qci2priority((qci - 5));
  }else{
    isH2H = true;
    priority  = qci2priority(qci);
   }
   bool suc=false;
  AddLClistElement(params.m_rnti, (uint8_t)(params.m_logicalChannelConfigList.back().m_logicalChannelIdentity) ,(uint64_t)(getSbr(qci)) ,priority ,isH2H,suc);
//sbr is initially gbrUl - params.m_logicalChannelConfigList.back().m_eRabGuaranteedBitrateUl

  std::map <uint16_t, pfsFlowPerf_t>::iterator it;
  for (uint16_t i = 0; i < params.m_logicalChannelConfigList.size (); i++)
    {
      it = m_flowStatsDl.find (params.m_rnti);

      if (it == m_flowStatsDl.end ())
        {
          pfsFlowPerf_t flowStatsDl;
          flowStatsDl.flowStart = Simulator::Now ();
          flowStatsDl.totalBytesTransmitted = 0;
          flowStatsDl.lastTtiBytesTrasmitted = 0;
          flowStatsDl.lastAveragedThroughput = 1;
          m_flowStatsDl.insert (std::pair<uint16_t, pfsFlowPerf_t> (params.m_rnti, flowStatsDl));
          pfsFlowPerf_t flowStatsUl;
          flowStatsUl.flowStart = Simulator::Now ();
          flowStatsUl.totalBytesTransmitted = 0;
          flowStatsUl.lastTtiBytesTrasmitted = 0;
          flowStatsUl.lastAveragedThroughput = 1;
          m_flowStatsUl.insert (std::pair<uint16_t, pfsFlowPerf_t> (params.m_rnti, flowStatsUl));
        }
      else
        {
          NS_LOG_ERROR ("RNTI already exists");
        }
    }

  return;
}



























void
PfFfMacScheduler::DoSchedUlTriggerReq (const struct FfMacSchedSapProvider::SchedUlTriggerReqParameters& params)
{
  NS_LOG_FUNCTION (this << " UL - Frame no. " << (params.m_sfnSf >> 4) << " subframe no. " << (0xF & params.m_sfnSf));

  RefreshUlCqiMaps ();
  std::vector <bool> rbMap;
  std::set <uint16_t> rntiAllocated;
  std::map <uint16_t,uint32_t>::iterator it;
//  std::map <uint16_t, std::vector <uint16_t> > allocationMap;
  std::vector<uint16_t> activeUser;
  std::map <uint16_t, pfsFlowPerf_t>::iterator itStats;
  FfMacSchedSapUser::SchedUlConfigIndParameters ret;
  std::vector<uint16_t> rbgAllocationMap;
  //std::list<LC_element> LC_List;
  double time = Simulator::Now().GetMilliSeconds();
  int rbAllocatedNum=0;
  int nflows = 0;
  int tempC2=10, tempC3=10, tempC4=10;
  double lambda = 0.4;
  int rbgNum = m_cschedCellConfig.m_ulBandwidth;
  int m2mLmt = lambda*rbgNum;
  std::list<LC_element>::iterator iter;
  bool tempSched[totUsers+1];
// Dynamic

  // update with RACH allocation map
  rbgAllocationMap = m_rachAllocationMap;
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


//HARQ PROCESSING

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




  for(int i=1; i< totUsers+1; i++)
  tempSched[i]=false;
  tti++;
 std::cout<<"\n----------------- TTI-"<<tti<<" ---------------------\n";



    for (it = m_ceBsrRxed.begin (); it != m_ceBsrRxed.end (); it++)
    {
       std::set <uint16_t>::iterator itRnti = rntiAllocated.find ((*it).first);
      // select UEs with queues not empty and not yet allocated for HARQ
      if (((*it).second > 0)&&(itRnti == rntiAllocated.end ()))
		{
      // remove old entries of this UE-LC
      
          nflows++;
          activeUser.push_back ((*it).first);
          std::cout<<"SIZE of User: " << (*it).first << " is: "<< (*it).second << std::endl;
        }

    }

if(activeUser.size()>0)
{
	c2--;
	c3--;
	c4--;
}
  if (nflows == 0)
    {
      c2=tempC2;
      c3=tempC3;
      c4=tempC4;
     return ; // no flows to be scheduled
    }


	std::cout<<"\ActiveUsers  : "<<nflows;


//-------Populate Queue----------


std::cout<<"value of c2: "<<c2<<std::endl;
std::cout<<"value of c3: "<<c3<<std::endl;
std::cout<<"value of c4: "<<c4<<std::endl;
if(c2 == 0)
{
  std::cout<<"\n---Inside C2---\n";

  for(iter = LC_list.begin();iter != LC_list.end();++iter)
  {
    if(activeUser.find(activeUser.begin(),activeUser.end(),iter->rnti)!=activeUser.end() && iter->priority==2)
    {
     std::cout<<"@@@@User Starved : "<<it->rnti<<"\t"<<it->isH2H<<"\t";
     AddLClistElement(iter->rnti, (uint16_t)iter->lcid ,(uint64_t)iter->sbr ,1,(bool)iter->isH2H,(bool)iter->SuccessOrNot);
     LC_list.erase(iter);
	}
  }
  c2=tempC2;
}

if(c3 == 0)
{
  std::cout<<"\n---Inside C3---\n";

  for(iter = LC_list.begin();iter != LC_list.end();++iter)
  {
    if(activeUser.find(activeUser.begin(),activeUser.end(),iter->rnti)!=activeUser.end() && iter->priority==3)
    {
     std::cout<<"@@@@User Starved : "<<it->rnti<<"\t"<<it->isH2H<<"\t";
     AddLClistElement(iter->rnti, (uint16_t)iter->lcid ,(uint64_t)iter->sbr ,2,(bool)iter->isH2H,(bool)iter->SuccessOrNot);
     LC_list.erase(iter);
	}
  }
  c3=tempC3;
}


if(c4 == 0)
{
  std::cout<<"\n---Inside C4---\n";

  for(iter = LC_list.begin();iter != LC_list.end();++iter)
  {
    if(activeUser.find(activeUser.begin(),activeUser.end(),iter->rnti)!=activeUser.end() && iter->priority==4)
    {
     std::cout<<"@@@@User Starved : "<<it->rnti<<"\t"<<it->isH2H<<"\t";
     AddLClistElement(iter->rnti, (uint16_t)iter->lcid ,(uint64_t)iter->sbr ,3,(bool)iter->isH2H,(bool)iter->SuccessOrNot);
     LC_list.erase(iter);
	}
  }
  c4=tempC4;
}


// --------------------USER INDEX ARRAY FILLING-------------------------//
  std::vector<std::vector<uint16_t> > array(LC_list.size()+1, std::vector<uint16_t> ( m_cschedCellConfig.m_ulBandwidth, 0 ) );;
	int mcs;
	uint64_t tbSize;
  for(iter = LC_list.begin();iter != LC_list.end() && iter->SuccessOrNot==false;++iter)
  {
      std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueCqi.find (iter->rnti);
      uint64_t data_pend = (uint64_t)(iter->sbr)*0.001;
	  if (itCqi == m_ueCqi.end ())
		{
		    mcs = 0;
		}
		else
		{
	      for(int startIndex=0; startIndex < m_cschedCellConfig.m_ulBandwidth; startIndex++)
	      {

	         int cqi = 0;
	         int mcs;
	         int endIndex = startIndex;
	         bool flag=false;
		     double minSinr = (*itCqi).second.at (startIndex);
			 if (minSinr == NO_SINR)
			 {
				minSinr = EstimateUlSinr (iter->rnti, startIndex);
			 }


		   // std::cout << "\n----report for while loop-----when start index is: " << startIndex << std::endl;

		    while( ( endIndex < m_cschedCellConfig.m_ulBandwidth ) && ( data_pend > 0 ) )
		    {
			//std::cout << "data_Pend is: " << data_pend << "\tchunk-size: " << chunkSize << "\tnext-allocation is: " << endIndex << std::endl;
					int cqi = 0;

					if ((*itCqi).second.at (endIndex) < minSinr)
					{
						minSinr = (*itCqi).second.at (endIndex);
					}
					double s = log2 ( 1 + (std::pow (10, minSinr / 10 )  /( (-std::log (5.0 * 0.00005 )) / 1.5) ));
					cqi = m_amc->GetCqiFromSpectralEfficiency (s);
					mcs = m_amc->GetMcsFromCqi (cqi);
		   		    tbSize = (uint64_t)(m_amc->GetTbSizeFromMcs (mcs,chunkSize));
                    if(data_pend<=tbSize)
				    {
					flag=true;
					break;
				    }
					endIndex ++;
			}
            if(flag)
            {
                    array[iter->rnti][startIndex] = endIndex-startIndex+1;
            }
            else
            {
                    array[iter->rnti][startIndex] = endIndex-startIndex;
            }
      	}
	}






//============Printing UserIndexArray==============
  for(iter = LC_list.begin();iter != LC_list.end() && iter->SuccessOrNot==false;++iter)
  {
    std::cout << "\nUser : " << iter->rnti << " metric is \n\n\n" << std::endl;

     for(int y=0; y < m_cschedCellConfig.m_ulBandwidth; ++y)
      {
	std::cout << array[iter->rnti][y] << "\t";
      }
      std::cout<<std::endl;







//====================Main Algo=================
	int m2mRbg = 0;
	for(iter=LC_list.begin();iter!=LC_list.end() && iter->SuccessOrNot==false;iter++)
	{
        if((!(iter->isH2H)) && (m2mRbg >= m2mLmt))
	    {
     		continue;
        }

       std::map <uint16_t,uint32_t>::iterator it = m_ceBsrRxed.find (iter->rnti);

    	if(it == m_ceBsrRxed.end () || it->second <= 0)
        {
	     std::cout<<"BSR EMPTY"<<std::endl;
	     NS_LOG_INFO(this << " Bsr");
	     continue;
        }
        bool free,satisfied=false;
        int min_rb=array[iter->rnti][0],k;
        for(j=0;j<m_cschedCellConfig.m_ulBandwidth;j++)
        {
			free=true;
			for(k=j;k<j+array[iter->rnti][j];k++)
			{
				if(rbMap.at(k))
				{
					free=false;
					break;
				}
			}
			if(free==true && array[iter->rnti][j]<=mini)
			{
				satisfied=true;
				save_start_index=j;
				min_rb=array[iter->rnti][j];
			}
        }
        if(satisfied)
        {
			iter->SuccessOrNot=true;
			for(k=save_start_index;k<save_start_index+array[iter->rnti][save_start_index];k++)
			{
				rbMap.at(k)=true;
				rbgAllocationMap.at(k)=iter->rnti;
				if(!(iter->isH2H))
				m2mrbg++;
			}
        }
        else
        break;
	}





//===============Filling ULDCI Array============
uint16_t user,size;
start=0;
while(start<rbgAllocationMap.size())
{
  user=rbgAllocationMap.at(start);
  size=0;

  while( (start+size < rbgAllocationMap.size()) && (user == rbgAllocationMap.at(start+size)))
  {
    size++;
  }
  //size=count-i;

//  std::cout<<"value of start "<<start<<" rbneeded "<<size<<" rnti "<< user << std::endl;
  UlDciListElement_s uldci;
  uldci.m_rnti = user;
  uldci.m_rbStart = start;
  uldci.m_rbLen = size;
  std::map <uint16_t, std::vector <double> >::iterator itCqi = m_ueCqi.find (user);
  int cqi = 0;
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
//                              NS_LOG_DEBUG (this << " UE " <<  (*it).first << " minsinr " << minSinr << " -> mcs " << (uint16_t)uldci.m_mcs);
	}
    }

    uldci.m_tbSize = (m_amc->GetTbSizeFromMcs (uldci.m_mcs, uldci.m_rbLen) / 8);

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
//	  std::cout << "USER: " << uldci.m_rnti << " TBSIZE: " << uldci.m_tbSize << std::endl;
	  NS_LOG_DEBUG (this << " EACH USER UE " << uldci.m_rnti << " startPRB " << (uint32_t)uldci.m_rbStart << " nPRB " << (uint32_t)uldci.m_rbLen << " CQI " << cqi << " MCS " << (uint32_t)uldci.m_mcs << " TBsize " << uldci.m_tbSize << " RbAlloc " << start);
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
	   // NS_LOG_DEBUG (this << " UE bytes txed " << (*it).second.lastTtiBytesTrasmitted);
	  }
	  else
	  {
	    NS_LOG_DEBUG (this << " No Stats for this allocated UE");
	  }
  // Dynamic
  tempSched[uldci.m_rnti] = true;
}

      start=start+size;		// populating rbgallocationMap
}

	std::cout<<"\n----waiting queue-----\n";
  // Dynamic
  for(iter=LC_list.begin();iter!=LC_list.end();iter++)
  {
    if(iter->SuccessOrNot==false)
    {
		waitedInQueue[iter->rnti]++;
		cout<<"\n------rnTi--"<<iter->rnti<<"------waited Time====="<<waitedInQueue[iter->rnti]<<"\n";
    }
    else
    {
		waitedInQueue[iter->rnti]=0;
    }
  }


    if((nflows==nettotal)&&settb)
    settb=false;

    for (itStats = m_flowStatsUl.begin (); itStats != m_flowStatsUl.end (); itStats++)
    {
      (*itStats).second.totalBytesTransmitted += (*itStats).second.lastTtiBytesTrasmitted;
      // update average throughput (see eq. 12.3 of Sec 12.3.1.2 of LTE – The UMTS Long Term Evolution, Ed Wiley)
//      std::cout<<"User "<<(*itStats).first <<" : avg thr: "<<(*itStats).second.lastAveragedThroughput<<std::endl;
      (*itStats).second.lastAveragedThroughput = ((1.0 - (1.0 / m_timeWindow)) * (*itStats).second.lastAveragedThroughput) + ((1.0 / m_timeWindow) * (double)((*itStats).second.lastTtiBytesTrasmitted / 0.001));
      //       NS_LOG_DEBUG (this << " UE tot bytes " << (*itStats).second.totalBytesTransmitted);
      //       NS_LOG_DEBUG (this << " UE avg thr " << (*itStats).second.lastAveragedThroughput);
      (*itStats).second.lastTtiBytesTrasmitted = 0;
    }

//================================= RB ALLOC LOG TEST
    int count=0;
    std::cout<<"******************RBGALLOCATION***************"<<std::endl;
    for(uint16_t y=0;y<rbgAllocationMap.size();++y)
    {
	    std::cout<<rbgAllocationMap.at(y)<<"\t";
	    if(rbgAllocationMap.at(y)==0)
	    {
		    ++count;
	    }
    }
    std::cout<<std::endl;
    std::cout<<"******TOTAL FREE RB******* "<<count<<std::endl;
//===================================================

  m_allocationMaps.insert (std::pair <uint16_t, std::vector <uint16_t> > (params.m_sfnSf, rbgAllocationMap));
  m_schedSapUser->SchedUlConfigInd (ret);
  return;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~







void
PfFfMacScheduler::AddLClistElement(uint16_t rnti, uint8_t lcid ,uint64_t sbr,uint8_t  priority, bool isH2H,bool suc)
{
  int cnt=0;
  std::list<LC_element>::iterator it;
  for(it=LC_list.begin();it!=list.end();it++)
  {
		if(it->rnti==rnti && it->priority==priority)
		{
			cnt=1;
			break;
		}
  }
  if(totUsers < rnti)
    totUsers = rnti;
  it=LC_list.begin();
  if(cnt==0)
  {
  NS_LOG_INFO (this << " RNTI " << rnti <<"lcid " <<(uint16_t)lcid );
  struct  LC_element newListElem;
  newListElem.rnti = rnti;
  newListElem.lcid = lcid;
  newListElem.sbr = sbr;
  newListElem.priority = priority;
  newListElem.isH2H = isH2H;
  newListElem.SuccessOrNot=suc;

  
  if(it->isH2H)
  {
		if(priority==1)
		{
			//do nothing//
		}
		else if(priority==4)
		{
			while(it!=LC_list.end() && priority!=4)
			{
				it++;
			}
		}
		else
		{
			while(it!=LC_list.end() && priority<it->priority)
			{
				if(it->isH2H==false && it->priority>1)
				break;
			}
		}
		LC_list.insert(it,newListElem);
  }
  else
  {
		if(priority==1)
		{
			while(it!=LC_list.end() && it->priority==1)
			{
				it++;
			}
		}
		else if(priority==4)
		{
			it=LC_list.end();
		}
		else
		{
			while(it!=LC_list.end() && it->priority==1)
			{
				it++;
			}
			if(it!=LC_list.end())
			{
				while(it!=LC_list.end())
				{
					if((it->isH2H==false && priority<=it->priority) || it->priority==4)
					{
						break;
					}
				}
			}
		}
		LC_list.insert(it,newListElem);
  }
}




/*######################################################################################################3
######################################################################################################3
######################################################################################################3
#######################################################################################################3*/
