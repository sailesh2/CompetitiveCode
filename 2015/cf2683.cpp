#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,k,s,cnt=0;
    cin>>n;
    if(n<6)
    {
        if(n==4)
        {
            cout<<"YES\n";
            cout<<"4 * 3 = 12\n";
            cout<<"12 * 2 = 24\n";
            cout<<"24 * 1 = 24\n";
        }
        else if(n==5)
        {
            cout<<"YES\n";
            cout<<"5 - 2 = 3\n";
            cout<<"4 * 3 = 12\n";
            cout<<"3 - 1 = 2\n";
            cout<<"12 * 2 = 24\n";
        }
        else
            cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
        cout<<"5 - 3 = 2\n";
        cout<<"2 - 2 = 0\n";
        cout<<"0 * 1 = 0\n";
        cout<<"6 * 4 = 24\n";
        k=n;
        while(k>6)
        {
            cout<<k<<" * 0 = 0\n";
            k--;
        }
        cout<<"0 + 24 = 24\n";
    }
    return 0;
}
