#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,j,k,ctr=0,cnt;
    cin>>n;
    int has[100005]={0};
    int ans[100005][2];
    for(i=2;i<=n;i++)
    {
        cnt=0;
        for(j=i;j<=n;j=j+i)
        {
            if(cnt==0)
            {
                if(has[j]==0)
                {
                    k=j;
                    cnt=1-cnt;
                }
            }
            else
            {
                if(has[j]==0)
                {
                    ans[ctr][0]=k;
                    ans[ctr][1]=j;
                    has[k]=1;
                    has[j]=1;
                    cnt=1-cnt;
                    ctr++;
                }
            }
        }
    }
    cout<<ctr<<"\n";
    for(i=0;i<ctr;i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    return 0;
}
