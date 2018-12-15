#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    int n,ke=0,ko=0,i;
    cin>>n;
    int arr[n],brr[n],ev[n],od[n];
    map<int,int> mp;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%2==0)
            ev[ke++]=arr[i];
        else
            od[ko++]=arr[i];
    }
    sort(ev,ev+ke);
    sort(od,od+ko);
    int j=0;
    for(i=0;i<ko;i++)
    {
        brr[j]=od[i];
        j=j+2;
    }
    j=1;
    for(i=0;i<ke;i++)
    {
        brr[j]=ev[i];
        j=j+2;
    }
    int temp,ctr=0;
    for(i=0;i<n;i++)
        mp.insert(make_pair(brr[i],i));
    for(i=0;i<n;i++)
    {

        j=(mp.find(arr[i]))->second;
        while(j!=i)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            ctr++;
            j=(mp.find(arr[i]))->second;

        }
    }
    cout<<ctr;
    return 0;
}
