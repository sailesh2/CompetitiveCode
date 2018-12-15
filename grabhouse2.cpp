#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,n,j;
    cin>>n;
    int poww=pow(2,n);

    int arr[poww][poww];
    for(i=0;i<poww;i++)
    {
        for(j=0;j<i;j++)
        {
            cin>>arr[i][j];
        }
    }
    int res[poww],res1[poww];
    for(i=0;i<poww;i++)
        res[i]=i;
    int k=0,ctr=poww,cnt=0,ctr2;
    while(1)
    {
        if(ctr==1)
            break;
        ctr2=0;
        if(cnt==0)
        {
            for(i=0;i<ctr;i++)
            {
                if(i+1>=ctr)
                {
                    res1[ctr2++]=res[i];
                    break;
                }
                if(res[i]>res[i+1])
                {
                    if(arr[res[i]][res[i+1]]==1)
                    {
                        res1[ctr2++]=res[i];
                    }
                    else
                    {
                        res1[ctr2++]=res[i+1];
                    }
                }
                else
                {
                    if(arr[res[i+1]][res[i]]==1)
                    {
                        res1[ctr2++]=res[i+1];
                    }
                    else
                    {
                        res1[ctr2++]=res[i];
                    }
                }
                i++;
            }
        }
        else
        {
            for(i=0;i<ctr;i++)
            {
                if(i+1>=ctr)
                {
                    res[ctr2++]=res1[i];
                    break;
                }
                if(res1[i]>res1[i+1])
                {
                    if(arr[res1[i]][res1[i+1]]==1)
                    {
                        res[ctr2++]=res1[i];
                    }
                    else
                    {
                        res[ctr2++]=res1[i+1];
                    }
                }
                else
                {
                    if(arr[res1[i+1]][res1[i]]==1)
                    {
                        res[ctr2++]=res1[i+1];
                    }
                    else
                    {
                        res[ctr2++]=res1[i];
                    }
                }
                i++;
            }
        }

        ctr=ctr2;
        cnt=1-cnt;
    }
    if(cnt==0)
        cout<<res[0]+1;
    else
        cout<<res1[0]+1;
    return 0;
}
