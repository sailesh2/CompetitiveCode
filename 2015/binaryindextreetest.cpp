#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int arr[5]={0,1,2,4,5};
    int i,idx,val,f[5]={0},sum;
    for(i=1;i<=5;i++)
    {
        idx=i;
        val=arr[i-1];
        while (idx <=5)
        {
        //    cout<<idx<<" ";
            f[idx-1] = (f[idx-1] + val)%3;
            idx += (idx & -idx);
        }
        //cout<<"\n";
    }
    for(i=1;i<=5;i++)
    {
        idx=i;
        sum = 0;
        while (idx > 0)
        {
            sum = (sum + f[idx-1])%3;
            idx -= (idx & -idx);
        }
        cout<<sum<<" ";
    }
    idx=4;
    val=1;
    while (idx <=5)
    {
        f[idx-1] = (f[idx-1] + val)%3;
        idx += (idx & -idx);
    }
    cout<<"\n";
    for(i=1;i<=5;i++)
    {
        idx=i;
        sum = 0;
        while (idx > 0)
        {
            sum = (sum + f[idx-1])%3;
            idx -= (idx & -idx);
        }
        cout<<sum<<" ";
    }


    return 0;
}
