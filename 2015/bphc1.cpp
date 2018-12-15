#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i,t,l,n,s,j,save,ctr,save2;
    long long int sm=0;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>l>>n>>s;
        int arr[n];
        for(j=0;j<n;j++)
            cin>>arr[j];
        sort(arr,arr+n);
        sm=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]>s)
            {
                sm=sm+n-1-j;
            }
            else
            {
                ctr=1;
                save=j;
                save2=save;
                while(1)
                {
                    while(save+ctr<n && arr[save+ctr]-arr[j]<=s)
                    {
                        save2=save+ctr;
                        ctr=ctr*2;
                    }
                    ctr=1;
                    if(save==save2)
                        break;
                    save=save2;
                }
                sm=sm+(n-1)-save;


                ctr=1;
                save=j;
                save2=save;
                while(1)
                {
                    while(save+ctr<n && l-arr[save+ctr]>s)
                    {
                        save2=save+ctr;
                        ctr=ctr*2;
                    }
                    ctr=1;
                    if(save==save2)
                        break;
                    save=save2;
                }
                sm=sm+save-j;
            }
        }
        cout<<sm<<"\n";
    }
    return 0;
}
