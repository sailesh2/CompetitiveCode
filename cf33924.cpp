#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    long long int maincnt=0,i,n,j,sm=0,cnt,ctr;
    cin>>n;
    string x,p="1";
    for(i=0;i<n;i++)
    {

        cin>>x;
        if(x=="0")
        {
            p=x;
            maincnt=1;
        }
        j=0;
        cnt=0;
        ctr=0;
        while(j<x.length())
        {
            if(x[j]!='0' && x[j]!='1')
            {
                p=x;
                cnt=1;
                break;
            }
            if(x[j]=='1')
                ctr=ctr+1;
            if(ctr>1)
            {
                p=x;
                cnt=1;
                break;
            }
            j=j+1;
        }
        if(cnt==0)
            sm=sm+x.length()-1;

    }
    if(maincnt==1)
        cout<<"0";
    else
    {
        cout<<p;
        for(i=0;i<sm;i++)
            cout<<"0";
    }
    return 0;
}

