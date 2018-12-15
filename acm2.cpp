#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main()
{
    int i,t,lt,j,n,q,x;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        char crr[200];
        cin>>s;
        lt=s.length();
        for(j=0;j<lt;j++)
            crr[j]=s[j];
        sort(crr,crr+lt);
        cin>>n>>q;
        for(j=0;j<q;j++)
        {
            cin>>x;
            if(x>lt*n)
                cout<<"-1\n";
            else
                cout<<crr[(x-1)/n]<<"\n";
        }
    }
    return 0;
}
