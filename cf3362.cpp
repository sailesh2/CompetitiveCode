#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    long long int sm=0;
    int bz[b.length()];
    int bo[b.length()];
    int i,init,fin,smz=0,smo=0;
    for(i=0;i<b.length();i++)
    {
        if(b[i]=='0')
        {
            smz++;
        }
        else
        {
            smo++;
        }
        bz[i]=smz;
        bo[i]=smo;
    }
    for(i=0;i<a.length();i++)
    {
        init=i;
        fin=b.length()-(a.length()-i);
        if(a[i]=='0')
        {
            if(init==0)
                sm=sm+bo[fin];
            else
                sm=sm+bo[fin]-bo[init-1];
        }
        else
        {
            if(init==0)
                sm=sm+bz[fin];
            else
                sm=sm+bz[fin]-bz[init-1];
        }
    }
    cout<<sm;
    return 0;
}
