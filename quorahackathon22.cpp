#include<stdio.h>
#include<iostream>

using namespace std;
int arr[102];
long double brr[102];
int n;
long double mini=1000;
int has[102]={0};
void fun(int,long double,long double);

int main()
{
    int i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i]>>brr[i];
    }
    for(i=0;i<n;i++)
    {
        //cout<<i<<"\n"<<"\n";
        has[i]=1;
        fun(1,arr[i],brr[i]);
        has[i]=0;
    }
    printf("%llf",mini);
    return 0;
}
void fun(int ctr,long double sm,long double p)
{
    //cout<<ctr<<"  "<<mini<<" "<<sm<<"        ";
    if(ctr>=n)
    {
        if(sm<=mini)
            mini=sm;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(has[j]==0)
        {
            if(sm+arr[j]*p<mini)
            {
      //          cout<<j<<"\n";
                has[j]=1;
                fun(ctr+1,sm+arr[j]*p,p*brr[j]);
                has[j]=0;
            }
        }
    }
}
