#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<conio.h>
#include <algorithm>
using namespace std;


int main()
{
	int l,wid,h,a,b,c,d,e,f,N,i,p,q,r,t,k,chen,sergey,cnt1,cnt2,cnt3,savp,savq,savr,ctr1,ctr2,ctr3,u,v,w;
	cin>>t;
  	for(i=0;i<t;i++)
    {
    	cin>>l>>wid>>h>>a>>b>>c>>d>>e>>f>>p>>q>>r>>N;
    	k=(2*N)+1;
    	sergey=0;
	    if(p!=a)
	      cnt1=0;
	    else
	      cnt1=N+1;
	    if(q!=b)
	      cnt2=0;
	    else
	      cnt2=N+1;
	    if(r!=c)
	      cnt3=0;
	    else
	      cnt3=N+1;
	    for(u=-1*N;u<=N;u++)
      	{
				if(u==cnt1)
				continue;
				for(v=-1*N;v<=N;v++)
        		{
					if(v==cnt2)
					continue;
        			for(w=-1*N;w<=N;w++)
          			{
							if(w==cnt3)
							continue;
							savp=p;
					    	savq=q;
					    	savr=r;
					    	int arr[51][51][51]={0};
					    	ctr1=1;
					    	ctr2=1;
					    	ctr3=1;
					        while(1)
            				{
                            if(arr[savp][savq][savr]==2)
							break;
							arr[savp][savq][savr]++;

            				if(savp==a && savq==b && savr==c)
			              	{
									sergey++;
			              			break;
							}
			    			if(savp==0 || savp==l)
			              		ctr1=-1*ctr1;
			          		if(savq==0 || savq==wid)
			                  ctr2=-1*ctr2;
			            	if(savr==0 || savr==h)
			                  ctr3=-1*ctr3;
				            savp=savp+(ctr1*u);
				            savq=savq+(ctr2*v);
				            savr=savr+(ctr3*w);
         					}
      				}
    			}
    	}
    	cout<<sergey<<" ";


    	chen=0;
    	if(p!=d)
      	cnt1=0;
    	else
      	cnt1=N+1;
	    if(q!=e)
	      cnt2=0;
	    else
	      cnt2=N+1;
	    if(r!=f)
	      cnt3=0;
	    else
	      cnt3=N+1;
	    for(u=-1*N;u<=N;u++)
      	{
				if(u==cnt1)
				continue;
	      	for(v=-1*N;v<=N;v++)
	        {
	            	if(v==cnt2)
					continue;
		        	for(w=-1*N;w<=N;w++)
		        	{
		             	if(w==cnt3)
						continue;
				        savp=p;
				    	savq=q;
				    	savr=r;
				    	int arr[51][51][51]={0};
						ctr1=1;
						ctr2=1;
						ctr3=1;
					    while(1)
		            	{
							if(arr[savp][savq][savr]==2)
							break;
							arr[savp][savq][savr]++;
							if(savp==d && savq==e && savr==f)
				              {
									chen++;
				              		break;
				              }
		    				if(savp==0 || savp==l)
		              		ctr1=-1*ctr1;
		          			if(savq==0 || savq==wid)
		                    ctr2=-1*ctr2;
		            		if(savr==0 || savr==h)
		                  	ctr3=-1*ctr3;
				            savp=savp+(ctr1*u);
				            savq=savq+(ctr2*v);
				            savr=savr+(ctr3*w);
		         	   }
					}
    		}
    	}
    	cout<<chen<<"\n";
  	}
  	getch();
    return 0;
}
