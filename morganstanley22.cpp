#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,t,j,n,ins,d,r;
    cin>>t;
    long long int cnt,sm,diff,insd,deld;
    string s1,s2;
    for(i=0;i<t;i++)
    {
        insd=0;
        deld=0;
        cin>>s1;
        cin>>s2;
        cin>>d>>ins>>r;
        sm=0,cnt=0;
        int ctr1[300]={0},ctr2[300]={0};
        for(j=0;j<s1.length();j++)
        {
            ctr1[(int)s1[j]]++;
        }
        for(j=0;j<s2.length();j++)
        {
            ctr2[(int)s2[j]]++;
        }
        for(j=0;j<300;j++)
        {
            diff=ctr2[j]-ctr1[j];
                if(diff<0)
                    insd=insd+(-1*diff);
                else
                    deld=deld+diff;
        }
        if(ins+d>r)
        {
            sm=sm+min(insd,deld)*r;
                if(insd>deld)
                {
                    sm=sm+(insd-deld)*d;
                }
                else
                {
                    sm=sm+ins*((deld-insd));
                }
        }
        else
        {
            sm=sm+insd*d+deld*ins;
        }
        cout<<sm<<"\n";
    }
    return 0;
}
