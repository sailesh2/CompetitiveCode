#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,i,a,b;
    cin>>n;
    int arr[4]={0};
    arr[n]=1;
    for(i=0;i<3;i++)
    {
        cin>>a>>b;
        if(arr[a]==1)
        {
            arr[1]=0;
            arr[2]=0;
            arr[3]=0;
            arr[b]=1;
        }
        else if(arr[b]==1)
        {
            arr[1]=0;
            arr[2]=0;
            arr[3]=0;
            arr[a]=1;
        }
        else
        {

        }
    }
    for(i=1;i<=3;i++)
    {
        if(arr[i]==1)
        {
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}
