#include<stdio.h>
#include<iostream>
#include<math.h>
#include<utility>
#include<stdlib.h>

using namespace std;


int n;
int arr[100];
long long int maxi=0;
void fun(int);

int main()
{
    int i,j,t;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>n;
        for(j=0;j<n;j++)
            cin>>arr[j];
        fun(1);
        cout<<maxi<<"\n";
    }
    return 0;
}
void fun(int i)
{
    int nva;
    if(i>=n/2)
    {
        int j;
        int brr[n];
        for(j=0;j<n;j++)
            brr[j]=arr[j];
        for(j=i;j<n-1;j++)
        {
            if(brr[j-1]%2==0 && brr[j+1]%2==0)
            {
                nva=(brr[j-1]+brr[j+1])/2;
                if(abs(nva-brr[n-1-j])>=abs(brr[j]-brr[n-1-j]))
                   brr[j]=nva;
            }
        }


        long long int s=0;
        for(j=0;j<n/2;j++)
            s=s+abs(brr[j]-brr[n-1-j]);
        //cout<<i<<" "<<s<<"\n";
        if(s>maxi)
            maxi=s;
        return;
    }
    int save;
    if(arr[i-1]%2==0 && arr[i+1]%2==0)
    {
        save=arr[i];
        nva=(arr[i-1]+arr[i+1])/2;
        arr[i]=nva;
        fun(i+1);
        arr[i]=save;
    }
    fun(i+1);
}
