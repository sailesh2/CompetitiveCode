#include<stdio.h>
#include<iostream>

using namespace std;

int n;
long long int fun(int,int,int,int,long long int sav[100][100]);
int main()
{
    int i,t,m,j;
    long long int ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        long long int save[100][100]={0};
        ctr=fun(0,m,0,0,save);
        cout<<ctr%1000000007<<"\n";
    }
}
long long int fun(int i,int m,int cd,int cm,long long int sav[100][100])
{
    if(i==n)
    {
        return 1;
    }
    long long int sm=0;
    if(cd>=(cm+1)*m)
    {
        if(sav[i+1][cd-(cm+1)]==0)
            sm=sm+fun(i+1,m,cd,cm+1,sav);
        else
            sm=sm+sav[i+1][cd-(cm+1)];
    }
    if(sav[i+1][cd+1-cm]==0)
        sm=sm+fun(i+1,m,cd+1,cm,sav);
    else
        sm=sm+sav[i+1][cd+1-cm];
    sav[i][cd-cm]=sm;
    return sm;
}
