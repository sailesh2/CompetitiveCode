#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,h,v;
    cin>>n;
    int hor[100]={0},ver[100]={0};
    int ans[n],k=0;
    for(i=0;i<n*n;i++)
    {
        cin>>h>>v;
        if(hor[h]==0 && ver[v]==0)
        {
            hor[h]=1;
            ver[v]=1;
            ans[k]=i+1;
            k++;
        }
    }
    for(i=0;i<k;i++)
        cout<<ans[i]<<" ";
    return 0;
}
