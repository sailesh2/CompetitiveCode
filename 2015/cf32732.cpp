#include<stdio.h>
#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    int i,n,j,ctr=0,maxi=0;
    cin>>n;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int save=0,val;
    for(i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
            ctr++;
        else
        {

            ctr=ctr/2;
            if(ctr>maxi)
                maxi=ctr;
            val=0;
            for(j=save+1;j<i-1;j++)
            {
                val++;
                if(val>(i-1-(save+1))/2)
                    break;
                arr[j]=arr[j-1];
            }
            for(;j<i-1;j++)
                arr[j]=arr[i-1];
            ctr=0;
            save=i;
        }
    }
     ctr=ctr/2;
            if(ctr>maxi)
                maxi=ctr;
            val=0;
            for(j=save+1;j<i-1;j++)
            {
                val++;
                if(val>(i-1-(save+1))/2)
                    break;
                arr[j]=arr[j-1];
            }
            for(;j<i-1;j++)
                arr[j]=arr[i-1];


    cout<<maxi<<"\n";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
