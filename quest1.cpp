#include<stdio.h>
#include<iostream>

using namespace std;

int n,m;
long long int sav[101][101];
int arr[101][101]={0};
long long int fun(int,int);
int main()
{
    int i,j,q,x,y,p;
    cin>>n>>m>>q;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            sav[i][j]=-1;
    }
    for(i=0;i<q;i++)
    {
        cin>>x>>y>>p;
        arr[x][y]+=p;
    }
    long long int maxi=0,a;
    for(i=0;i<m;i++)
    {
        if((a=fun(0,i))>=maxi)
            maxi=a;
    }
    cout<<maxi;
    return 0;
}
long long int fun(int i,int j)
{
    long long int s=0,maxi=0;
    if(i+1<n && j-1>=0)
    {
        if(sav[i+1][j-1]==-1)
            s=fun(i+1,j-1);
        else
            s=sav[i+1][j-1];
    }
    if(s>=maxi)
        maxi=s;
    if(i+1<n)
    {
        if(sav[i+1][j]==-1)
            s=fun(i+1,j);
        else
            s=sav[i+1][j];
    }
    if(s>=maxi)
        maxi=s;
    if(i+1<n && j+1<m)
    {
        if(sav[i+1][j+1]==-1)
            s=fun(i+1,j+1);
        else
            s=sav[i+1][j+1];
    }
    if(s>=maxi)
        maxi=s;
    sav[i][j]=maxi+arr[i][j];
    return sav[i][j];
}
