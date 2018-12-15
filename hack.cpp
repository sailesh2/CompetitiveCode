#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void fun(long long int,long long int,long long int*,long long int brr[100][100],long long int*,long long int*);
long long int max=0,n;
int main()
{
    int i,t;
    long long int k,j,sum=0;
    scanf("%d",&t);
    long long int answ[t],arr[100],brr[100][100],crr[100]={0},drr[100];
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&drr[j]);
            brr[drr[j]][crr[drr[j]]]=j;
            crr[drr[j]]++;
        }
        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }
        fun(0,sum+arr[0],arr,brr,crr,drr);
        k=drr[0];
        for(j=1;j<n;j++)
        {
            if(drr[j]<=k)
            {
                k=drr[j];
                fun(j,sum+arr[j],arr,brr,crr,drr);
            }
        }
		answ[i]=max;
		max=0;
    }
    for(i=0;i<t;i++)
    {
		printf("%lld\n",answ[i]);
    }

    return 0;
}
void fun(long long int k,long long int sum,long long int *arr,long long int brr[100][100],long long int *crr,long long int *drr)
{
    if(sum>=max)
        max=sum;
    long long int j,ctr;
    for(j=k+1;j<n;j++)
    {
        if(drr[j]>drr[k])
        {
            fun(j,sum+arr[j],arr,brr,crr,drr);
            ctr=drr[k]+1;
            while(ctr<=drr[j])
            {
                long long int l;
                for(l=0;l<crr[ctr];l++)
                {
                    if(brr[ctr][l]>j)
                        fun(brr[ctr][l],sum+arr[brr[ctr][l]],arr,brr,crr,drr);
                }
                ctr++;
            }

         }

    }
}
