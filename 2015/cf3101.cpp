#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    int i,n;
    cin>>n;
    cin>>s;
    int z=0,o=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
            z++;
        else
            o++;
    }
    cout<<n-2*min(z,o);
    return 0;
}
