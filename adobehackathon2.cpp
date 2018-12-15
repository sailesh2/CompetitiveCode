#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,j;
    cin>>n;
    int arr[n],brr[n],k;
    long long int val,ans,p;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int fac[1000005]={0};
    for(i=0;i<n;i++)
    {
        val=arr[i];
        //cout<<val<<"\n";
        j=1;
        while(j*j<=val)
        {
            if(val%j==0)
            {
                if(j==val/j)
                    fac[j]++;
                else
                {
                    fac[j]++;
                    fac[val/j]++;
                }
      //          cout<<j<<" "<<val/j<<"\n";
            }
            j=j+1;
        }
    }
    //cout<<"\n\n";
    //for(i=0;i<n;i++)
    //    cout<<arr[i]<<" ";
    //cout<<fac[3]<<"---";
    for(i=0;i<n;i++)
    {
        val=fac[arr[i]];
        //cout<<arr[i]<<"++";
        //cout<<val<<"\n";
        k=0;
        while(val>0)
        {
            brr[k++]=val%2;
            val=val/2;
        }
        p=2;
        ans=1;
        for(j=0;j<k;j++)
        {
            if(brr[j]==1)
                ans=(ans*p)%1000000007;
            p=(p*p)%1000000007;
        }
        ans=(ans-1)%1000000007;
        if(ans<0)
            ans=ans+1000000007;
        cout<<ans<<" ";
    }
    return 0;
}
