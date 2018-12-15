#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,j,n,k,p,cnt,sav,cnt2;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k>>p;
        cnt=0;
        int arr[k];
        for(j=0;j<k;j++)
            cin>>arr[j];
        sort(arr,arr+k);
        sav=0;
        cnt2=0;
        for(j=0;j<k;j++)
        {
            if(cnt>=p)
            {
                cnt2=1;
                break;
            }
            cnt=cnt+arr[j]-1-sav;
            sav=arr[j];
        }
        if(cnt2==1)
        {
            cnt=cnt-arr[j-1]+1+sav;
            cout<<sav+p-cnt<<"\n";
        }
        else
        {
            if(cnt>=p)
            {
                cnt=cnt-arr[j-1]+1+sav;
                cout<<sav+p-cnt<<"\n";
            }
            else
            {
                if(arr[j-1]+p-cnt<=n)
                    cout<<arr[j-1]+p-cnt<<"\n";
                else
                    cout<<"-1\n";
            }
        }
    }
    return 0;
}

