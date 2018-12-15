#include<stdio.h>
#include<iostream>

using namespace std;

int arr[100][100];
int crr[100]={0};
int has[100]={0};
int mini;
void fun(int,int,int);

int main()
{
    int i,x,y,n,m,q,l;
    cin>>n>>m>>q>>l;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        arr[x][crr[x]]=y;
        crr[x]++;
        arr[y][crr[y]]=x;
        crr[y]++;
    }

    for(i=0;i<q;i++)
    {
        mini=10000000;
        cin>>x>>y;
        has[x]=1;
        fun(x,y,0);
        has[x]=0;
        cout<<mini*l;
    }
    return 0;
}
void fun(int x,int y,int ctr)
{
    if(x==y)
    {
        if(ctr<=mini)
            mini=ctr;
        return;
    }
    for(int i=0;i<crr[x];i++)
    {
        if(has[arr[x][i]]==0)
        {
            has[arr[x][i]]=1;
            fun(arr[x][i],y,ctr+1);
            has[arr[x][i]]=0;
        }
    }
}
