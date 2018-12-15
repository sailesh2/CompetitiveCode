#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,q,j,a,b,c;
    cin>>n>>q;
    long long int arr[200001]={0},k;
    for(i=0;i<q;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            k=1;
            for(j=b;j<=c;j++)
            {
                arr[j]=(arr[j]+k*(k+1))%1000000007;
                k++;
            }
        }
        else
        {
            k=0;
            for(j=b;j<=c;j++)
                k=(k+arr[j])%1000000007;
            cout<<k<<"\n";
        }
    }
    return 0;
}
