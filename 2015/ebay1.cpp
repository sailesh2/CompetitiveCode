#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

long long int k,n;
long long int ctr=0;

void fun(vector<long long int> *,long long int,long long int *);
int main()
{
    long long int i,j,a,b;
    cin>>n>>k;
    vector<long long int> arr[n+1];
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
    }
    long long int brr[1000000]={0};
    fun(arr,1,brr);
    cout<<ctr;
    return 0;
}
void fun(vector<long long int> *arr,long long int i,long long int *brr)
{
    long long int idx,j;
    idx=k/i;
    long long int sum = 0;
    if(idx>n)
        idx=n;
    while (idx > 0)
    {
        sum = (sum + brr[idx]);
        idx -= (idx & -idx);
    }
    ctr=ctr+sum;

    idx=i;
    long long int val=1;
    while (idx <=n)
    {
        brr[idx] = brr[idx] + val;
        idx += (idx & -idx);
    }
    for(j=0;j<arr[i].size();j++)
        fun(arr,arr[i][j],brr);


    idx=i;
    val=-1;
    while (idx <=n)
    {
        brr[idx] = brr[idx] + val;
        idx += (idx & -idx);
    }
    return;
}
