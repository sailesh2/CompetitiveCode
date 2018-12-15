#include<stdio.h>
#include<iostream>
#include<string.h>


using namespace std;

int main()
{
    int i,j,t;
    char s[100005];
    cin>>t;
    int ctr=0;
    char c;

    for(i=0;i<t;i++)
    {
        //s=raw_input()
        scanf("%s",s);
        c=s[0];
        j=1;
        ctr=0;
        while(s[j]!='\0')
        {
            if(s[j]==c)
                ctr=ctr+1;
            else
                c=s[j];
            j=j+1;
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
