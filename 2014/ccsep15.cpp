#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,lt,cnt;
    long long int p,k;
    cin>>t;
    string s;
    for(i=0;i<t;i++)
    {
        cin>>s;
        lt=s.length();
        p=1;
        k=0;
        cnt=0;
        j=0;
        while(j<lt)
        {
            p=(p*2)%1000000007;
            if(s[j]=='l')
                k=(k*2)%1000000007;
            else
                k=(k*2+1)%1000000007;
            cnt=1-cnt;
            j=j+1;
        }
        if(cnt==0)
            cout<<(((6*k+2*p+1)%1000000007)*(333333336%1000000007))%1000000007<<"\n";
        else
            cout<<(((6*k+2*p+2)%1000000007)*(333333336%1000000007))%1000000007<<"\n";
    }
    return 0;
}

