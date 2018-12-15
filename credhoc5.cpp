#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,x,y,p,j;
    cin>>n;
    cin>>x>>y;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int sm[100000]={0};
    if(y%x!=0)
        cout<<"IMPOSSIBLE";
    else
    {
        p=y/x;
        sm[1]=1;
        for(i=0;i<n;i++)
        {
            for(j=p;j>=0;j--)
            {
                if(sm[j]==1)
                {
                    if(j*arr[i]<=p)
                        sm[j*arr[i]]=1;
                    if(j*arr[i]==p)
                        break;
                }
            }
        }
        if(sm[p]==1)
            cout<<"POSSIBLE";
        else
            cout<<"IMPOSSIBLE";
    }
    return 0;
}
