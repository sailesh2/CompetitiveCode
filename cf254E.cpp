#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,i,a,d,val,idx;
    cin>>n>>m;
    long long int arr[100000]={0},sum,b,c;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            cin>>d;
            val=d;
            idx=b;
            while (idx <=n)
            {
                arr[idx-1] += val;
                idx += (idx & -idx);
            }
            val=-1*d;
            idx=c+1;
            while (idx <=n)
            {
                arr[idx-1] += val;
                idx += (idx & -idx);
            }
        }
        else
        {
            idx=c;
            sum = 0;
            while (idx > 0)
            {
                sum += arr[idx-1];
                idx -= (idx & -idx);
            }
            idx=b-1;
            while (idx > 0)
            {
                sum -= arr[idx-1];
                idx -= (idx & -idx);
            }
            cout<<sum-((b*(b+1))/2-(c*(c-1)/2))<<"\n";
        }
    }
    return 0;
}
