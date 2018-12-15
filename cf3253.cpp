#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    long long int arr[n][3];
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int j,ctr=0;
    long long int v,d;
    int ans[n],k=0;
    for(i=0;i<n;i++)
    {
        if(arr[i][2]>=0)
        {
            ctr++;
            ans[k++]=i+1;
            v=arr[i][0];
            d=0;
            for(j=i+1;j<n;j++)
            {
                if(arr[j][2]>=0)
                {
                    if(v==0)
                        break;
                    arr[j][2]=arr[j][2]-v-d;
                    if(arr[j][2]<0)
                        d=d+arr[j][1];
                    v--;
                }
            }
            for(;j<n;j++)
            {
                if(arr[j][2]>=0)
                {
                    arr[j][2]=arr[j][2]-d;
                    if(arr[j][2]<0)
                        d=d+arr[j][1];
                }
            }
        }
    }
    cout<<ctr<<"\n";
    for(i=0;i<k;i++)
        cout<<ans[i]<<" ";
    return 0;
}
