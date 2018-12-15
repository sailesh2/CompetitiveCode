#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,k,a,b,p,num;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int sum[5005]={0};
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a>>b;
            for(k=a;k<=b;k++)
                sum[k]++;
        }
        cin>>p;
        int ans[p];

        for(j=0;j<p;j++)
        {
            cin>>num;
            ans[j]=sum[num];
        }
         cout<<"Case #"<<i+1<<": ";
        for(j=0;j<p;j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
