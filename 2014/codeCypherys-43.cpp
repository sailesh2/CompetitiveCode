#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,n,k,lt,cnt;
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cnt=0;
        cin>>s>>n;
        lt=s.length();
        int crr[300]={0};
        for(j=0;j<lt;j++)
        {
            if(s[j]>='A' && s[j]<='Z')
            {
                cnt=1;
                crr[(int)s[j]]++;
            }
        }
        if(cnt==1)
        {
        if(n%2==0)
        {
            for(j=int('A');j<=int('Z');j++)
            {
                for(k=0;k<crr[j];k++)
                    cout<<char(j);
            }
            cout<<"\n";
        }
        else
        {
            for(j=int('Z');j>=int('A');j--)
            {
                for(k=0;k<crr[j];k++)
                    cout<<char(j);
            }
            cout<<"\n";
        }
        }
        else
            cout<<"NULL\n";
    }
    return 0;
}
