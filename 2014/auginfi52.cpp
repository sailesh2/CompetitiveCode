#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,n,j,q,x,cnt;
    cin>>n;
    int arr[n],temp[n+1],temp2[n+1],ans[n];
    for(i=0;i<n;i++)
    {
        ans[i]=0;
        temp[i]=1;
        temp2[i]=0;
        cin>>arr[i];
    }
    temp[i]=1;
    temp2[i]=0;
    cnt=0;
    i=0;
    while(i<n)
    {
        j=n-1-i;
        if(cnt==0)
            temp2[n-i]=0;
        else
            temp[n-i]=0;
        while(j>=0)
        {
            if(cnt==0)
                temp2[j]=(((((arr[j])%100003)*(temp[j+1]%100003))%100003)+(temp2[j+1]%100003))%100003;
            else
                temp[j]=(((((arr[j])%100003)*(temp2[j+1]%100003))%100003)+(temp[j+1]%100003))%100003;
            j=j-1;
        }
        if(cnt==0)
            ans[i]=temp2[0]%100003;
        else
            ans[i]=temp[0]%100003;
        cnt=1-cnt;
        i=i+1;
    }
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x;
        cout<<ans[x-1]<<"\n";
    }
    return 0;
}
