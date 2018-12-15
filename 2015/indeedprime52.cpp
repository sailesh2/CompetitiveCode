#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,k;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>xrr[i]>>srr[i]>>arr[i]>>brr[i];
    }
    int sum[n][k];
    for(i=0;i<n;i++)
    {
        s=arr[i];
        p=xrr[i];
        if(s<=k)
        {
            if(has[s]==0)
            {
                has[s]=p;
            }
            else
            {
                has[s]=max(has[s],p);
            }

            for(j=0;j<srr[i];j++)
            {
                s=s+brr[j];
                p=p+xrr[i];
                if(s<=k)
                {
                    if(has[s]==0)
                    {
                        has[s]=p;
                    }
                    else
                    {
                        has[s]=max(has[s],p);
                    }
                }
                else
                    break;
            }
        }
    }
    fun(k);
}
fun(int k)
{
    for(i=1;i<)
}
