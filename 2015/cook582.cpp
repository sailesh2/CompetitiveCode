#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int i,j,t,sm,maxi,l,l2,kt,j2;
    char k,save;
    string s;
    char ns[1000001];

    char dee[202];
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        maxi=0;
        cin>>s;
        int crr[300]={0};
        kt=0;
        for(j=0;j<s.length();j++)
        {
            if(crr[(int)s[j]]==0)
                dee[kt++]=s[j];
            crr[(int)s[j]]++;
            if(crr[(int)s[j]]>=maxi)
            {
                maxi=crr[(int)s[j]];
                save=s[j];
            }
        }
        for(k='a';k<='z';k++)
        {
            if(save!=k)
            sm=sm+crr[(int)k];
        }
        if(maxi-1<=sm)
        {
            l=0;
            j=0;
            while(j<2*maxi-1)
            {
                ns[j]=save;
                if(dee[l]==save)
                    l++;
                if(l<kt)
                {
                    ns[j+1]=dee[l];
                    crr[(int)dee[l]]--;
                    if(crr[(int)dee[l]]==0)
                        l++;
                    j=j+2;
                }
                else
                    j=j+1;
            }
            for(j2=0;j2<j;j2++)
            {
                if(ns[j2]==save)
                {
                    l2=l;
                    if(dee[l2]==save)
                        l2++;
                    while(l2<kt)
                    {
                        if(dee[l2]!=save && crr[(int)dee[l2]]>0)
                        {
                            cout<<dee[l2];
                            crr[(int)dee[l2]]--;
                        }
                        l2++;
                    }
                }
                cout<<ns[j2];
            }
            cout<<"\n";
        }
        else
            cout<<"-1\n";
    }
    return 0;
}
