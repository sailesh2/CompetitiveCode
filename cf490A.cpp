#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,t1=0,t2=0,t3=0,mini=0;
    cin>>n;
    int arr[n];
    int t1ar[n];
    int t3ar[n];
    int t2ar[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
        {
            t1ar[t1]=i+1;
            t1++;
        }
        if(arr[i]==2)
        {
            t2ar[t2]=i+1;
            t2++;
        }
        if(arr[i]==3)
        {
            t3ar[t3]=i+1;
            t3++;
        }
    }
    mini=min(min(t1,t2),t3);
    t1=0;
    t2=0;
    t3=0;
    cout<<mini<<"\n";
    for(i=0;i<mini;i++)
    {
        cout<<t1ar[t1++]<<" "<<t2ar[t2++]<<" "<<t3ar[t3++]<<"\n";
    }
    return 0;
}
