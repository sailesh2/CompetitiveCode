#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string s;
    int i,n,k=0;
    cin>>n;
    int crr[300]={0};
    char drr[n];
    cin>>s;
    for(i=0;i<n;i++)
    {
        if(crr[(int)s[i]]==0)
            drr[k++]=s[i];
        crr[(int)s[i]]++;
    }
    for(i=0;i<k;i++)
        cout<<drr[i];
    return 0;
}
