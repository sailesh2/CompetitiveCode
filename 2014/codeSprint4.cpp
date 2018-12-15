#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,j,len,cnt,temp,ind;
    char k;
    char c[300];
    string s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        len=s.length();
        for(j=0;j<len;j++)
            c[j]=s[j];
        int has[300]={0};
        has[(int)c[len-1]]=len;
        cnt=0;
        for(j=len-2;j>=0;j--)
        {
            for(k=c[j]+1;k<='z';k++)
            {
                if(has[(int)k]>0)
                {
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
            {
                ind=has[(int)k]-1;
                temp=(char)c[j];
                c[j]=(char)k;
                c[ind]=temp;
                break;
            }
            has[(int)c[j]]=j+1;
        }
        if(cnt==1)
        {
            sort(c+j+1,c+len);
            for(j=0;j<len;j++)
                cout<<c[j];
            cout<<"\n";
        }
        else
            cout<<"no answer\n";
    }
    return 0;
}
