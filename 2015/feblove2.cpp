#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int d1,m1,y1,d2,m2,y2;
    int i,t,ctr;
    string s1,s2;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s1>>s2;
        ctr=0;
        d1=((int)s1[0]-48)*10+((int)s1[1]-48);
        m1=((int)s1[3]-48)*10+((int)s1[4]-48);
        y1=((int)s1[6]-48)*1000+((int)s1[7]-48)*100+((int)s1[8]-48)*10+((int)s1[9]-48);

        d2=((int)s2[0]-48)*10+((int)s2[1]-48);
        m2=((int)s2[3]-48)*10+((int)s2[4]-48);
        y2=((int)s2[6]-48)*1000+((int)s2[7]-48)*100+((int)s2[8]-48)*10+((int)s2[9]-48);


    }
}
