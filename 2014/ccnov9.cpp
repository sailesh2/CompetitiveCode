#include<stdio.h>
#include<iostream>

using namespace std;

int arr[10][10];
int n;
int fun(int,int *,int *);

int main()
{
    int i,t,j,k;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1;k++)
                cin>>arr[j][k];
        }
        int brr[10]={0};
        int has[10]={0};
        int a=fun(0,brr,has);
        for(j=0;j<n;j++)
            cout<<brr[j]<<" ";
        cout<<"\n";
    }
    return 0;
}
int fun(int ctr,int *brr,int *has)
{
    int j,cnt,k,b,l,i;
    if(ctr==n)
    {
       /*for(j=0;j<n;j++)
            cout<<brr[j]<<" ";
        cout<<"\n";*/

        int stor[10]={0};
        cnt=0;
        for(j=1;j<=n;j++)
        {
            for(i=0;i<n;i++)
            {
                if(stor[i]==0)
                {
                    l=0;
                    cnt=0;
                    for(k=0;k<n;k++)
                    {
                        if(brr[k]!=j)
                        {
                            b=brr[k];
                            if(b>j)
                                b=b-1;
                            if(b!=arr[i][l])
                            {
                                cnt=1;
                                break;
                            }
                            else
                                l++;
                        }
                    }
                    if(cnt==0)
                    {
                        stor[i]=1;
                        break;
                    }
                }
            }
            if(cnt==1)
                break;
        }

        //cout<<cnt<<"\n";
        return cnt;
    }
    for(j=1;j<=n;j++)
    {
        if(has[j]==0)
        {
            brr[ctr]=j;
            has[j]=1;
            if(fun(ctr+1,brr,has)==0)
                return 0;
            has[j]=0;
        }
    }
    return 1;
}
