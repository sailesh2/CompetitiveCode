#include<stdio.h>
#include<iostream>

using namespace std;

long long int dp[100005]={0};
int arr[100005]={0};
int n;
long long int fun(int i,int val,int giv);
int main()
{
    int i,j;
    cin>>n;
    int fac[100005]={0},maxi=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    for(j=1;j<=maxi;j++)
    {
 //       cout<<"--j"<<j<<"\n";
        for(i=0;i<n;i++)
            dp[i]=0;

        fac[j]=fun(0,j,j);
   //     cout<<arr[0]<<"--arr";
    }


    for(i=0;i<n;i++)
        cout<<fac[arr[i]]%1000000007<<" ";

    return 0;
}
long long int fun(int i,int val,int giv)
{
    //cout<<i<<" ";
    if(i==n)
    {
        return 0;
    }
    int j;
    int save=val;
        if(dp[i]==0)
        {
            int a,temp,gcd,val2=arr[i];
      //      cout<<"val"<<val<<"val2"<<i<<" ";
            if(val>=val2)
            {
                while(1)
                {
                    if(val%val2==0)
                    {
                        gcd=val2;
                        break;
                    }
                    temp=val;
                    val=val2;
                    val2=temp%val2;
                }
            }
            else
            {
                while(1)
                {
                    if(val2%val==0)
                    {
                        gcd=val;
                        break;
                    }
                    temp=val2;
                    val2=val;
                    val=temp%val;
                }
            }
            if(gcd==giv)
                a=1;
            else
                a=0;
            if(gcd%giv==0)
            {
            //fac[gcd]++;
            a=fun(i+1,gcd,giv);
            }
            a=a+fun(i+1,save,giv);
        dp[i]=a;
        }
        return dp[i];
}
