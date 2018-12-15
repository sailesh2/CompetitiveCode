#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,n,cnt,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        int arr[n][n];
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                cin>>arr[j][k];
            }
        }
        int left[n][n];
        int top[n][n];
        for(j=0;j<n;j++)
        {
            cnt=0;
            for(k=0;k<n;k++)
            {
                if(arr[j][k]==0)
                {
                    cnt++;
                }
                else
                    cnt=0;
                left[j][k]=cnt;
            }
        }
        for(j=0;j<n;j++)
        {
            cnt=0;
            for(k=0;k<n;k++)
            {
                if(arr[k][j]==0)
                {
                    cnt++;
                }
                else
                    cnt=0;
                top[k][j]=cnt;
            }
        }


        cnt=0;
        int ans[200][200]={0};
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(arr[j][k]==1)
                {
                    if(j-1>=0 && k-1>=0)
                        ans[j][k]=min(min(left[j][k-1],top[j-1][k]),ans[j-1][k-1])+1;
                    else
                        ans[j][k]=1;
                    cnt=cnt+ans[j][k];
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
