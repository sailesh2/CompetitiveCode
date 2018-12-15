#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,s,m,i,a,b,c,d,sm,l,j;
    cin>>n>>s>>m;
    int arr[100005]={0};
    int crr[100005]={0};
    vector<vector<int> > srr;

    for(i=0;i<s;i++)
    {
        vector<int> v;
        cin>>l;
        crr[i+1]=l;
        for(j=0;j<l;j++)
        {
            cin>>a;
            v.push_back(a);
        }
        srr.push_back(v);
    }
    for(i=0;i<m;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            for(j=0;j<crr[b];j++)
                arr[srr[b-1][j]]=(arr[srr[b-1][j]]+c)%1000000009;
        }
        else if(a==2)
        {
            cin>>b;
            sm=0;
            for(j=0;j<crr[b];j++)
                sm=(sm+arr[srr[b-1][j]])%1000000009;
            cout<<sm<<"\n";
        }
        else if(a==3)
        {
            cin>>b>>c>>d;
            for(j=b;j<=c;j++)
                arr[j]=(arr[j]+d)%1000000009;
        }
        else
        {
            cin>>b>>c;
            sm=0;
            for(j=b;j<=c;j++)
                sm=(sm+arr[j])%1000000009;
            cout<<sm<<"\n";
        }
    }
    return 0;
}
