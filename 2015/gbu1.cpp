#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,n;
    cin>>n;
    char arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            arr[i][j]='0';
    }
    for(i=0;i<n;i++)
        arr[0][i]='*';
    j=n-2;
    for(i=1;i<n-1;i++)
    {
        arr[i][j]='*';
        j--;
    }
    for(i=0;i<n;i++)
        arr[n-1][i]='*';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='0')
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}
