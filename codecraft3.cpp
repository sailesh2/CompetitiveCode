#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    int i,t,j,lt;
    long long int sm,ctr,ctr2;
    cin>>t;
    for(j=0;j<t;j++)
    {
        sm=0;
        ctr=0;
        ctr2=0;
        cin>>str;
        lt=str.length();
        long long int crr[1000005]={0};
        for(i=lt-1;i>=0;i--)
        {
            if(str[i]=='L')
                ctr++;
            if(str[i]=='O')
                crr[i]=ctr;
            if(i!=lt-1)
            crr[i]=crr[i]+crr[i+1];
        }
        for(i=0;i<lt;i++)
        {
            if(str[i]=='L')
            {
                ctr2++;
            }
            if(str[i]=='O')
            {
                sm=sm+ctr2*crr[i];
                ctr2=0;
            }
        }
        cout<<sm<<"\n";
    }
    return 0;
}
