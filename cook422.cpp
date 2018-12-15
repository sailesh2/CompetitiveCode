#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    int i,t,n,a,b,ctr,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        cin>>n;
        int arr[n],brr[n];
        for(j=0;j<n;j++)
        {
            cin>>arr[j]>>brr[j];
        }
        for(j=0;j<n;j++)
        {
            a=arr[j];
            b=brr[j];
            while(a!=b)
            {
                if(a==0 || b==0)
                    break;
                if(a>b)
                {
                    a=a%b;
                }
                else
                {
                    b=b%a;
                }
                ctr=(ctr+1)%2;
            }
        }
        cout<<ctr;
        if(ctr==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
