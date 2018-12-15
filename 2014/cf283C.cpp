#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int i,j,n,m,cnt,ctr;
    cin>>n>>m;
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        cin>>s;
        for(j=0;j<m;j++)
            arr[i][j]=int(s[j]);
    }
    int has[n],has1[n];
    for(i=0;i<n-1;i++)
        has[i]=1;
    ctr=0;
    for(j=0;j<m;j++)
    {
        cnt=0;
        for(i=0;i<n-1;i++)
        {
            if(has[i]==1)
            {
                if(arr[i+1][j]==arr[i][j])
                {
                    cnt=1;
                    has1[i]=1;
                }
                else if(arr[i+1][j]>arr[i][j])
                {
                    has1[i]=0;
                }
                else
                {
                    cnt=2;
                    break;
                }
            }
            else
                has1[i]=0;
        }
        if(cnt==2)
        {
            ctr++;
        }
        else if(cnt==0)
            break;
        else
        {
            for(i=0;i<n-1;i++)
                has[i]=has1[i];
        }
    }
    cout<<ctr;
    return 0;
}
