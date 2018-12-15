#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int arr[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cin>>arr[i][j];
    }
    if(n<2 || m<2)
        cout<<"-1\n";
    else
    {
    int mini=4,ctr;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                ctr=1;
                if(i-1>=0 && j+1<m)
                {
                    if(arr[i-1][j]==0)
                        ctr++;
                    if(arr[i-1][j+1]==0)
                        ctr++;
                    if(arr[i][j+1]==0)
                        ctr++;
                    if(ctr==4)
                    {
                        cnt=1;
                        if(cnt==1)
                        {
                            if(0<=mini)
                                mini=0;
                        }
                    }
                    else if(ctr==3)
                    {
                        if(arr[i-1][j]==1)
                        {
                            if(j-1>=0 || i-2>=0)
                                cnt=1;
                        }
                        else if(arr[i][j+1]==1)
                        {
                            if(j+2<m || i+1<n)
                                cnt=1;
                        }
                        else
                        {
                            if(j+2<m || i-2>=0)
                                cnt=1;
                        }
                        if(cnt==1)
                        {
                            if(1<=mini)
                                mini=1;
                        }
                    }
                    else if(ctr==2)
                    {
                        if(arr[i-1][j+1]==0)
                        {
                            if((i-2>=0 || j-1>=0)&&(j+2<m || i+1<n))
                                cnt=1;
                            if(cnt==1)
                            {
                            if(mini>2)
                                mini=2;
                            }
                        }
                        else
                        {
                            cnt=1;
                            if(cnt==1)
                            {
                            if(mini>1)
                                mini=1;
                            }
                        }
                    }
                    else
                    {
                        if(j+2<m || i+1 <n || i+2<n || j+1<m || i-2>=0 || j-1>=0)
                            cnt=1;
                        if(cnt==1)
                        {
                        if(mini>2)
                            mini=2;
                        }
                    }
                }
                ctr=1;
                if(i-1>=0 && j-1>=0)
                {
                    if(arr[i-1][j]==0)
                        ctr++;
                    if(arr[i-1][j-1]==0)
                        ctr++;
                    if(arr[i][j-1]==0)
                        ctr++;
                    if(ctr==4)
                    {
                            cnt=1;
                        if(4-ctr<=mini)
                            mini=4-ctr;
                    }
                    else if(ctr==3)
                    {
                        if(arr[i-1][j]==1)
                        {
                            if(j+1<m || i-2>=0)
                                cnt=1;
                        }
                        else if(arr[i][j-1]==1)
                        {
                            if(j+2<m || i+1<n)
                                cnt=1;
                        }
                        else
                        {
                            if(j+2<m || i-2>=0)
                                cnt=1;
                        }
                        if(cnt==1)
                        {
                            if(1<=mini)
                                mini=1;
                        }
                    }
                    else if(ctr==2)
                    {
                        if(arr[i-1][j-1]==0)
                        {
                            if(mini>2)
                                mini=2;
                        }
                        else
                        {
                            if(mini>1)
                                mini=1;
                        }
                    }
                    else
                    {
                        if(mini>2)
                            mini=2;
                    }
                }
                ctr=1;
                if(i+1<n && j-1>=0)
                {
                    if(arr[i+1][j]==0)
                        ctr++;
                    if(arr[i+1][j-1]==0)
                        ctr++;
                    if(arr[i][j-1]==0)
                        ctr++;
                    if(ctr==4 || ctr==3)
                    {
                        if(4-ctr<=mini)
                            mini=4-ctr;
                    }
                    else if(ctr==2)
                    {
                        if(arr[i+1][j-1]==0)
                        {
                            if(mini>2)
                                mini=2;
                        }
                        else
                        {
                            if(mini>1)
                                mini=1;
                        }
                    }
                    else
                    {
                        if(mini>2)
                            mini=2;
                    }
                }
                ctr=1;
                if(i+1<n && j+1<m)
                {
                    if(arr[i+1][j]==0)
                        ctr++;
                    if(arr[i+1][j+1]==0)
                        ctr++;
                    if(arr[i][j+1]==0)
                        ctr++;
                    if(ctr==4 || ctr==3)
                    {
                        if(4-ctr<=mini)
                            mini=4-ctr;
                    }
                    else if(ctr==2)
                    {
                        if(arr[i+1][j+1]==0)
                        {
                            if(mini>2)
                                mini=2;
                        }
                        else
                        {
                            if(mini>1)
                                mini=1;
                        }
                    }
                    else
                    {
                        if(mini>2)
                            mini=2;
                    }
                }
            }
        }
    }
    cout<<mini<<"\n";
    }
    return 0;
}
