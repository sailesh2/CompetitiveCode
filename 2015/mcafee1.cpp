#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    int i,j,n,k,q,l,r;
    cin>>n>>q;
    cin>>str;
    int crr[50005][26]={0};;
    for(i=0;i<n;i++)
    {
        if(i!=0)
        {
            for(j=0;j<26;j++)
                crr[i][j]=crr[i-1][j];
        }
        crr[i][(int)str[i]-97]++;
    }

    for(i=0;i<q;i++)
    {
        cin>>l>>r>>k;
        l--;
        r--;
        int tempar[26];
        for(j=0;j<26;j++)
        {
            if(l!=0)
                tempar[j]=crr[r][j]-crr[l-1][j];
            else
                tempar[j]=crr[r][j];
            if(j!=0)
                tempar[j]=tempar[j]+tempar[j-1];
        }
        for(j=25;j>=0;j--)
        {
            if(k>tempar[j])
                break;
        }
        if(j==25)
            cout<<"Out of range\n";
        else
            cout<<char(j+98)<<"\n";
    }
    return 0;
}
