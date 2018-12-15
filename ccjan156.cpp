#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,q,sum,idx,val,sumz,sumo,sumt,x,y,z,idx2,orig,newv;
    cin>>n>>q;
    int arr[n],zero[n],one[n],two[n],brr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=0;
        zero[i]=0;
        one[i]=0;
        two[i]=0;
    }
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
        if(i!=0)
            brr[i]=(brr[i-1]+brr[i])%3;
    }
    for(i=1;i<=n;i++)
    {
        val=1;
        if(brr[i-1]==0)
        {
            idx=i;
            while (idx <=n)
            {
                zero[idx-1] += val;
                idx += (idx & -idx);
            }
        }
        else if(brr[i-1]==1)
        {
            idx=i;
            while (idx <=n)
            {
                one[idx-1] += val;
                idx += (idx & -idx);
            }
        }
        else
        {
            idx=i;
            while (idx <=n)
            {
                two[idx-1] += val;
                idx += (idx & -idx);
            }
        }
        if(i!=1)
        val=brr[i-1]-brr[i-2];
        else
        val=brr[i-1];
        idx=i;
        while(idx<=n)
        {
            arr[idx-1] += val;
            idx += (idx & -idx);
        }
    }
    for(i=0;i<q;i++)
    {
        cin>>x>>y>>z;
        if(x==1)
        {
            idx=y;
            sum = 0;
            while (idx > 0)
            {
                sum += arr[idx-1];
                idx -= (idx & -idx);
            }
            val=z-sum;

            idx=y;
            while (idx <=n)
            {
                orig=arr[idx-1];
                arr[idx-1] += val;
                newv=arr[idx-1];

                if(orig==0)
                {
                    idx2=idx;
                    val=-1;
                    while(idx2<=n)
                    {
                        zero[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }

                }
                else if(orig==1)
                {
                    idx2=idx;
                    val=-1;
                    while(idx2<=n)
                    {
                        one[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }

                }
                else
                {
                    idx2=idx;
                    val=-1;
                    while(idx2<=n)
                    {
                        two[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }

                }


                if(newv==0)
                {
                    idx2=idx;
                    val=1;
                    while(idx2<=n)
                    {
                        zero[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }
                }
                else if(newv==1)
                {
                    idx2=idx;
                    val=1;
                    while(idx2<=n)
                    {
                        one[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }
                }
                else
                {
                    idx2=idx;
                    val=1;
                    while(idx2<=n)
                    {
                        two[idx2-1] += val;
                        idx2 += (idx2 & -idx2);
                    }
                }


                idx += (idx & -idx);
            }
        }
        else
        {
            idx=z;
            sum = 0;
            while (idx > 0)
            {
                sum += zero[idx-1];
                idx -= (idx & -idx);
            }
            sumz=sum;
            idx=y-1;
            sum = 0;
            if(idx>0)
            {
            while (idx > 0)
            {
                sum += zero[idx-1];
                idx -= (idx & -idx);
            }
            }
            sumz=sumz-sum;

            idx=z;
            sum = 0;
            while (idx > 0)
            {
                sum += one[idx-1];
                idx -= (idx & -idx);
            }
            sumo=sum;
            idx=y-1;
            sum = 0;
            if(idx>0)
            {
            while (idx > 0)
            {
                sum += one[idx-1];
                idx -= (idx & -idx);
            }
            }
            sumo=sumo-sum;

            idx=z;
            sum = 0;
            while (idx > 0)
            {
                sum += two[idx-1];
                idx -= (idx & -idx);
            }
            sumt=sum;
            idx=y-1;
            sum = 0;
            if(idx>0)
            {
            while (idx > 0)
            {
                sum += two[idx-1];
                idx -= (idx & -idx);
            }
            }
            sumt=sumt-sum;

            cout<<(sumz*(sumz+1))/2+(sumo*(sumo-1))/2+(sumt*(sumt-1))/2<<"\n";
        }
    }
	return 0;
}
