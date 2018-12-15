#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int n,m;
int counter=0;
int arr[1000000];
vector<int> v[1000000];
int has[1000000]={0};

void fun(int,int);

int main()
{
    int i,x,y;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    /*int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }*/
    fun(0,0);
    cout<<counter;
    return 0;
}
void fun(int i,int ctr)
{
    //cout<<i<<"\n";
    if(arr[i]==1)
        ctr++;
    else
        ctr=0;
    //cout<<"ctr--"<<ctr<<"\n";
    if(ctr>m)
    {
      //  cout<<"return here"<<"\n";
        return;
    }
    if(v[i].size()<=1 && i!=0)
    {
       //cout<<"return here2"<<"\n";

        counter++;
        return;
    }
    int j;
    has[i]=1;
    for(j=0;j<v[i].size();j++)
    {
        if(has[v[i][j]]==0)
        {
            fun(v[i][j],ctr);
        }
    }
    has[i]=0;
}
