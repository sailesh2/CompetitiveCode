#include<stdio.h>
#include<iostream>

using namespace std;

long long int has[1000001];
long long int sum=0;
long long int n;

void fun(int,long long int *,long long int);

int main()
{
    has[0]=0;
    long long int ctr=0,i,j,cnt=0;
    for(i=1;i<=1000000;i++)
    {
        cnt=0;
        ctr=0;
        n=i;
        while (n%2 == 0)
        {
            if(n<i)
            {
                ctr=ctr+has[n];
                cnt=1;
                break;
            }
            ctr++;
            n = n/2;
        }
        if(cnt==0)
        {
            for (j = 3; j*j <= n; j = j+2)
            {
                while (n%j == 0)
                {

                    if(n<i)
                    {
                        cnt=1;
                        ctr=ctr+has[n];
                        break;
                    }
                    ctr++;
                    n = n/j;
                }
                if(cnt==1)
                    break;
            }
        }

        if (cnt==0 && n > 2)
        {
            ctr++;
        }
        has[i]=ctr;
    }

    for(i=1;i<=1000000;i++)
        has[i]=has[i]+has[i-1];
    cin>>n;
    long long int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]=has[arr[i]];
    }
    fun(0,arr,0);
    cout<<sum;
    return 0;
}
void fun(int i, long long int *arr,long long int sm)
{
    if(i==n)
    {
        if(sm%2==0)
            sum=sum+sm;
    }
    fun(i+1,arr,sm);
    fun(i+1,arr,sm+arr[i]);
}
