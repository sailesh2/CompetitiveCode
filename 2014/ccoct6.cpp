#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,i,j,l,k,x,y,cnt;
    cin>>n>>m>>k;
    int has[300][300]={0};
    int ans[2000][2];
    for(i=0;i<k;i++)
    {
        cin>>x>>y;
        has[x][y]=1;
    }
    l=0;
    for(i=1;i<=n;i++)
    {
        cnt=0;
        for(j=1;j<=m;j++)
        {
            if(cnt==0 && has[i][j]==0)
            {
                cnt=1;
                ans[l][0]=i;
                ans[l][1]=j;
                l++;
            }
            if(has[i][j]==1)
                cnt=0;
        }
    }
    cout<<l<<"\n";
    for(i=0;i<l;i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<" 0\n";
    }
    return 0;
}
