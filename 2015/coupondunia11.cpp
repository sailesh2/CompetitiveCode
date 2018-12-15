#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,t;
    long long int a,c,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        c=(long long int)floor(sqrt(b))-(long long int)ceil(sqrt(a))+1;
        cout<<c<<"\n";
    }
    return 0;
}
