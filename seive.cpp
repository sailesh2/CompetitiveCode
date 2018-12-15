#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int seive[10000005];
int arr[10000005][11];
void pre()
{
    int i,j;
    for(i=2;i<=10000001;i++)
    {
        if(seive[i]==0)
        {
            seive[i]+=1;
            for(j=i*2;j<=10000001;j+=i)
            {
                seive[j]+=1;
            }
        }
    }
    for(i=2;i<=10000001;i++)
    {
    	for(j=0;j<11;j++)
    	arr[i][j]=arr[i-1][j];

        arr[i][seive[i]]++;
    }
}
int main()
{
    pre();
    int t,a,b,c;
    int i,j;

    cin>>t;
    i=0;
    while(t--)
    {
        cin>>a>>b>>c;
        cout<<"Case #"<<++i<<": ";
        if(c>10)
            cout<<"0\n";
        else
            cout<<arr[b][c]-arr[a-1][c]<<"\n";
    }
}
