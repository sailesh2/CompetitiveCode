#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,i,m,j,a,b,c,d;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        if(a==1)
        {
            cin>>d;
            for(j=b-1;j<=c-1;j++)
            {
                if(arr[j]%d==0)
                    arr[j]=arr[j]/d;
            }
        }
        else
        {
            arr[b-1]=c;
        }
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
