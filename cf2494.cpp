#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,j,n,m,sm=0,cnt;
    cin>>n>>m;
    string str;
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        cin>>str;
        for(j=0;j<m;j++)
        {
            arr[i][j]=(int)str[j]-48;
        }
    }
    //cout<<"gh";
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<m-1;j++)
        {
            cnt=0;
            if(arr[i][j]==0)
                cnt++;

            if(arr[i][j+1]==0)
                cnt++;

            if(arr[i+1][j]==0)
                cnt++;

            if(arr[i+1][j+1]==0)
                cnt++;

            cout<<cnt;
            if(cnt==3)
                sm=sm++;
            else if(cnt==4)
                sm=sm+4;
        }
    }
    cout<<sm;
    return 0;
}
