#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,x,q;
    int cnt=0,ctr=0;
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(x>q)
        {
            if(cnt==0)
                cnt=1;
            else
                break;
        }
        else
            ctr++;
    }
    cout<<ctr;
    return 0;
}
