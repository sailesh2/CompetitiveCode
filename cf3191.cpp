#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,x,ctr=0,two;
    cin>>n>>x;
    int i;
    for(i=1;i*i<=x;i++)
    {
        if(x%i==0)
        {
            two=x/i;
            if(i<=n && two<=n)
            {
                if(i==two)
                    ctr++;
                else
                    ctr=ctr+2;
            }
        }
    }
    cout<<ctr;
    return 0;
}
