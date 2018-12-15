#include<stdio.h>
#include<iostream>
#define gc getchar

using namespace std;

void scanint(long long int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}


int main()
{
    int i,t;
    long long int x,y;
    cin>>t;
    for(i=0;i<t;i++)
    {
        scanint(x);
        scanint(y);
        if(x==y)
            cout<<x<<"\n";
        else if(x%2==0)
        {
            if(abs(x-y)==2)
                cout<<"2\n";
            else
                cout<<"1\n";
        }
        else
            cout<<"1\n";
    }
    return 0;
}
