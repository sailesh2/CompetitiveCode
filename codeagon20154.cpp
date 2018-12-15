#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,m,i,j,x1,x2,y1,y2,z1,z2;
    cin>>n;
    int ctr,a,b,c;
    int arr[n][3];
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        ctr=0;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(j=0;j<n;j++)
        {
            a=arr[j][0];
            b=arr[j][1];
            c=arr[j][2];

            if(a<=x2 && a-4>=x1 && b<=y2 && b-4>=y1 && c<=z2 && c-4>=z1)
                ctr++;
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
