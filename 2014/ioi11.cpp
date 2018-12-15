#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,p,n,x,y;
    cin>>n>>p;
    string str;
    long long int s=0,rows=0,cols=0;
    int arr[p][3];
    int rowar[n],colar[n];
    for(i=0;i<p;i++)
    {
        cin>>str>>x>>y;

        arr[i][1]=x;
        arr[i][2]=y;
        if(str[0]=='R')
        {
            arr[i][0]=1;
            rowar[x]=i;
        }
        else
        {
            arr[i][0]=0;
            colar[x]=i;
        }
    }
    for(i=0;i<p;i++)
    {
        if(arr[i][0]==1)
        {
            if(rowar[arr[i][1]]==i)
            {
                s=s+n*arr[i][2]-cols;
                rows=rows+arr[i][2];
            }
        }
        else
        {
            if(colar[arr[i][1]]==i)
            {
                s=s+n*arr[i][2]-rows;
                cols=cols+arr[i][2];
            }
        }
    }
    cout<<s;
    return 0;
}
