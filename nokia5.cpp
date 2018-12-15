#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,n,j,q,val,ctr,mod=1000000007;
    cin>>n;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    cin>>q;
    int l=40010;
    int arra[40010]={0};
    arra[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=l-1;j>=0;j--)
        {
            if(arra[j]>0)
            {
                arra[j+arr[i]] =(arra[j+arr[i]]+1);
            }
        }
    }
    int cnt;
    int sum_arr[40010];
    int arrb[40010]={0};
    long long int sm=0;
    int k=0;
    for(i=0;i<l;i++)
    {
        if(arra[i]>0)
        {
            arrb[k]=i;
            sm=(sm+arra[i])%mod;
            sum_arr[k]=sm;
            k++;
        }
    }

    int brra[40010]={0};
    brra[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=l-1;j>=0;j--)
        {
            if(brra[j]>0)
            {
               brra[j+brr[i]]= (brra[j+brr[i]]+1);
            }
        }
    }

    int sum_brr[40010];
    int brrb[40010]={0};
    sm=0;
    int k1=0,save,save2;
    for(i=0;i<l;i++)
    {
        if(brra[i]>0)
        {
            brrb[k1]=i;
            sm=(sm+brra[i])%mod;
            sum_brr[k1]=sm;
            k1++;
        }
    }
    i=0;
    j=0;
    sm=0;
    while(i<k && j<k1)
    {
        while(i<k && j<k1)
        {
            if(abs(brrb[j]-arrb[i])<=q)
               {
               	if(brrb[j]>arrb[i])
               	cnt=0;
               else
               	cnt=1;

               	break;
               }
            if(brrb[j]>arrb[i])
                i++;
            if(brrb[j]<arrb[i])
                j++;
        }
        if(i>=k || j>=k1)
            break;
        if(cnt==0)
        {
	        val=brrb[j];
	        ctr=1;
	        save=i-1;
	        save2=i-1;
	        while(1)
	        {
	            save=save2;
	            ctr=1;
	            while(save+ctr<k && abs(val-arrb[save+ctr])<=q)
	            {
	                save2=save+ctr;
	                ctr=ctr*2;
	            }
	            if(save==save2)
	                break;
	        }
	        if(i==0)
         	sm=(sm+sum_arr[save])%mod;
        else
        {
        	if((sum_arr[save]-sum_arr[i-1])<0)
        		sm=((sm+(sum_arr[save]-sum_arr[i-1])+mod))%mod;
        	else
            	sm=(sm+sum_arr[save]-sum_arr[i-1])%mod;
        }

    j++;
        }
        else
    	{
    		val=arrb[i];
	        ctr=1;
	        save=j-1;
	        save2=j-1;
	        while(1)
	        {
	            save=save2;
	            ctr=1;
	            while(save+ctr<k1 && abs(val-brrb[save+ctr])<=q)
	            {
	                save2=save+ctr;
	                ctr=ctr*2;
	            }
	            if(save==save2)
	                break;
	        }
	        if(i==0)
         	sm=(sm+sum_brr[save])%mod;
        else
        {
        	if((sum_brr[save]-sum_brr[j-1])<0)
        		sm=((sm+(sum_brr[save]-sum_brr[j-1])+mod))%mod;
        	else
            	sm=(sm+sum_brr[save]-sum_brr[j-1])%mod;
        }

    	i++;
    	}

    }
    if(sm<0)
    	sm=(sm+mod)%mod;
    cout<<sm;
    return 0;
}
