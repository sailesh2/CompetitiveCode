#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,i,mini,j,s,m,d,des,sr,q,sm;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>s>>m>>d;
        des=m;
        sr=s;
        int dp[10000];
        int has[10000];
        for(j=0;j<1000;j++)
        {
            dp[j]=100000;
            has[j]=-1;
        }
        dp[m]=0;
        has[arr[m]]=m;
        for(j=m+1;j<n;j++)
        {
            if(has[arr[j]]==-1)
                mini=dp[j-1];
            else
                mini=min(dp[j-1],dp[has[arr[j]]]);
            has[arr[j]]=j;
            if(mini==-1)
                dp[j]=-1;
            else
                dp[j]=mini+1;
        }
        //for(j=m;j<n;j++)
        //    cout<<dp[j]<<" ";
        //cout<<"\n";
        j=0;
        if(has[arr[j]]==-1)
            dp[0]=-1;
        else
            dp[0]=dp[has[arr[j]]]+1;
        for(j=1;j<m;j++)
        {
            if(has[arr[j]]==-1)
                mini=dp[j-1];
            else
                mini=min(dp[j-1],dp[has[arr[j]]]);
            //has[arr[j]]=j;
            if(mini==-1)
                dp[j]=-1;
            else
                dp[j]=mini+1;
        }
        sm=dp[sr];

        //cout<<sm<<"\n";




        sr=m;
        des=d;
        for(j=0;j<1000;j++)
        {
            dp[j]=100000;
            has[j]=-1;
        }
        dp[des]=0;
        has[arr[des]]=des;
        for(j=des+1;j<n;j++)
        {
            if(has[arr[j]]==-1)
                mini=dp[j-1];
            else
                mini=min(dp[j-1],dp[has[arr[j]]]);
            has[arr[j]]=j;
            if(mini==-1)
                dp[j]=-1;
            else
                dp[j]=mini+1;
        }
        /*for(j=0;j<n;j++)
            cout<<has[j]<<" ";
        cout<<"\n";*/
        j=0;
        if(has[arr[j]]==-1)
            dp[0]=-1;
        else
            dp[0]=dp[has[arr[j]]]+1;
        for(j=1;j<des;j++)
        {
            if(has[arr[j]]==-1)
                mini=dp[j-1];
            else
                mini=min(dp[j-1],dp[has[arr[j]]]);
            //has[arr[j]]=j;
            if(mini==-1)
                dp[j]=-1;
            else
                dp[j]=mini+1;
        }
        /*for(j=0;j<n;j++)
            cout<<dp[j]<<" ";
        cout<<"\n";*/

        if(dp[sr]==-1 || sm==-1)
            sm=-1;
        else
            sm=sm+dp[sr];

        cout<<sm<<"\n";
    }
    return 0;
}
