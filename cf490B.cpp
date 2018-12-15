#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,save;
    cin>>n;
    int arr[n][2];
    int crr[1000005]={0};
    int brr[1000005]={0};
    for(i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        crr[arr[i][0]]++;
        crr[arr[i][1]]++;
        brr[arr[i][0]]=arr[i][1];
        if(arr[i][0]==0)
            save=i;
    }
    int ans[n];
    save=arr[save][1];
    for(i=1;i<n;i=i+2)
    {
        ans[i]=save;
        save=brr[save];
    }
    for(i=0;i<n;i++)
    {
        if(arr[i][0]!=0 && crr[arr[i][0]]==1)
            save=i;
    }
    save=arr[save][0];
    for(i=0;i<n;i=i+2)
    {
        ans[i]=save;
        save=brr[save];
    }
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
