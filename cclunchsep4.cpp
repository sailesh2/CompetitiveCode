#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,t,j,ctr,n,m,a,b,c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        ctr=0;
        int arr[n];
        int sav[n];
        sav[0]=0;
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
            if(j!=0)
            {
                if(arr[j]!=arr[j-1])
                {
                    ctr++;
                    //sav[i]=ctr;
                }
                sav[j]=ctr;
            }
        }
       // for(i=0;i<n;i++)
       //     cout<<sav[i];
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>a>>b>>c;
            if(a==1)
                cout<<sav[c-1]-sav[b-1]+1<<"\n";
        }
    }
    return 0;
}
