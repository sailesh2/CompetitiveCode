#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long int j,t,i,n,cnt,sm,save,k,p,saveval;
    cin>>t;
    for(j=0;j<t;j++)
    {
        sm=0;
        cnt=0;
        cin>>n;
        long long int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<n-1;i++)
        {
            if(cnt==0)
            {
                if(arr[i+1]<arr[i])
                {
                    cnt=1;
                    save=i;
                    saveval=arr[i];
                }
            }
            else if(cnt==1)
            {
                if(arr[i+1]>arr[i])
                {
                    cnt=2;
                }
            }
            else
            {
                if(arr[i+1]<arr[i])
                {
                    cnt=1;
                    p=min(arr[i],saveval);
                    for(k=i;k>=save;k--)
                    {
                        if(p-arr[k]>=0)
                        {
                            //cout<<k<<" "<<p-arr[k]<<"\n";
                            sm=(sm+p-arr[k])%1000000007;
                        }
                    }
                    save=i;
                    saveval=arr[i];
                }
            }
        }
        if(cnt==2)
        {
            p=min(arr[n-1],saveval);
            for(k=n-1;k>=save;k--)
            {
                if(p-arr[k]>=0)
                {
                    //cout<<k<<" "<<p-arr[k]<<"\n";
                    sm=sm+(p-arr[k])%1000000007;
                }
            }
        }
        cout<<sm%1000000007<<"\n";
    }
    return 0;
}

