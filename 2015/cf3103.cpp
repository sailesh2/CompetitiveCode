#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,j,n,m,k,save,x;
    cin>>n>>k;
    int arr[n+1];
    for(i=0;i<k;i++)
    {
        cin>>m;
        save=-1;
        for(j=0;j<m;j++)
        {
            cin>>x;
            if(save!=-1)
                arr[save]=x;
            save=x;
        }
        arr[save]=-1;
    }
    int ctr=0,cnt=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]==i+1)
        {
            if(cnt==1)
                ctr=ctr+2;
        }
        else if(arr[i]==-1)
        {
            cnt=1;
            ctr++;
        }
        else
        {
            cnt=1;
            ctr=ctr+2;
        }
    }
    cout<<ctr;
    return 0;
}
