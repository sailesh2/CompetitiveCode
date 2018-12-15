#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,p,q,cnt,x,y;
    cin>>n;
    cin>>p;
    cnt=0;
    int arr[1000]={0};
    for(i=0;i<p;i++)
    {
        cin>>x;
        arr[x]=1;
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>y;
        arr[y]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i]==0)
        {
            cnt=1;
            break;
        }
    }
    if(cnt==0)
        cout<<"I become the guy.";
    else
        cout<<"Oh, my keyboard!";
}
