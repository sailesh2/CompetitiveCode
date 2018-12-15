#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int i,t;
    cin>>t;
    long long int a,b,s;
    double a2,b2;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        b2=floor(sqrt(b));
        a2=floor(sqrt(a));
        s=(long long int)b2-(long long int)a2;
        if(a2*a2==a)
            s=s+1;
        cout<<s<<"\n";
    }
    return 0;
}
