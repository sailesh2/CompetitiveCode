#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int i,n;
    string s;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            cin>>s;
        if(n%2==0)
            cout<<n/2<<"\n";
        else
            cout<<(n+1)/2<<"\n";
    }
    return 0;
}
