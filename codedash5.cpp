#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string s;
    int i,j,t,sm,mini,lt;
    char c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int has[300]={0};
        int has1[300]={0};
        cin>>s;
        lt=s.length();
        if(lt%2==0)
        {
            sm=0;
            for(j=0;j<lt/2;j++)
            {
                has[(int)s[j]]++;
            }
            for(;j<lt;j++)
            {
                has1[(int)s[j]]++;
            }
            for(c='a';c<='z';c++)
            {
                if(has1[(int)c]>has[(int)c])
                    sm=sm+has1[(int)c]-has[(int)c];
            }
            mini=sm;
            sm=0;
            for(c='a';c<='z';c++)
            {
                if(has[(int)c]>has1[(int)c])
                    sm=sm+has[(int)c]-has1[(int)c];
            }
            if(sm<mini)
                mini=sm;
            cout<<mini<<"\n";
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
