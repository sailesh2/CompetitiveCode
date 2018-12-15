#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int l,i,j,k,n,t,a,b,c,d;
    cin>>t;
    for(l=0;l<t;l++)
    {
        cin>>n;
        int arr[n][n][n],brr[n][n][n],crr[n][n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    cin>>arr[i][j][k];
                    a=0;
                    b=0;
                    c=0;
                    d=0;
                    if(j>0)
                        a=arr[i][j-1][k];
                    if(k>0)
                        b=arr[i][j][k-1];
                    if(j>0 && k>0)
                        c=arr[i][j-1][k-1];
                    if(i>0)
                        d=crr[i-1][j][k];
                    brr[i][j][k]=arr[i][j][k]-(a+b-c)-d;
                    crr[i][j][k]=brr[i][j][k]+d;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                    cout<<brr[i][j][k]<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}
