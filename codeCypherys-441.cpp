#include<stdio.h>
#include<iostream>
#define gc getchar


using namespace std;



void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
    int i,ctr,cnt,j;
    int arr[301]={0};
    int crr[301]={0};

    i=3;
    ctr=1;
    arr[0]=2;
    crr[2]=1;
    long long int sm=2;
    while(i<=300)
    {
        cnt=0;
        if(i%2!=0)
        {
            j=0;
            while(j<ctr && arr[j]<=pow(i,0.5))
            {
                if(i%arr[j]==0)
                {
                    cnt=1;
                    break;
                }
                j=j+1;
            }
            if(cnt==0)
            {
                arr[ctr]=i;
                crr[i]=1;
                ctr=ctr+1;
            }
        }
        i=i+1;
    }
    int t;
    string s;
    cin>>t;
    i=0;
    while(i<t)
    {
        cin>>s;
        j=0;
        cnt=0;
        ans=[];
        while(j<len(s))
        {
            if crr[ord(s[j])]==1:
                cnt=1
            else:
                ans.append(s[j])
            j=j+1
        if cnt==1:
            print ''.join(ans)
        else:
            print "NULL"
        i=i+1
