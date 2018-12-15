#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int i,t,k,l,k1,j;
    string s;
    char x[1001];
    int arr[1001];
    cin>>t;
    long long int sm,a,b;
    for(i=0;i<t;i++)
    {
        k=0;
        k1=0;
        cin>>s;
        for(j=0;j<s.length();j++)
        {
            if(s[j]>='0' && s[j]<='9')
                arr[k++]=(int)s[j]-48;
            else if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/' || s[j]=='%')
                x[k1++]=s[j];
        }
        if(k==0)
            cout<<"-1\n";
        else
        {
            l=0;
            sm=arr[0];
            for(j=1;j<k;j++)
            {
                a=sm;
                b=arr[j];
                if(x[l]=='+' || x[l]=='*' || x[l]=='/')
                {
                    sm=a+b;
                }
                else
                {
                    sm=a-b;
                }
                l++;
            }
            cout<<sm<<"\n";
        }
    }
    return 0;
}
