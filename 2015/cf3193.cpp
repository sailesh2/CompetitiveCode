#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int i,n,j,m,sum=0;
    cin>>n>>m;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]=arr[i]%m;
    }
    int brr[1001]={0};
    sort(arr,arr+n);
    //brr[0]=1;
    int sum2;
    for(i=n-1;i>=0;i--)
    {
        vector<int> v;
        if(brr[0]==1)
            break;
        for(j=1000;j>=0;j--)
        {
            if(brr[j]==1)
                v.push_back((arr[i]+j)%m);
        }
        for(i=0;i<v.size();i++)
            brr[v[i]]=1;
        brr[arr[i]]=1;
    }
    if(brr[0]==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
