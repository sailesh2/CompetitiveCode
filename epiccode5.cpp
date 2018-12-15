#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;


map<int,int> mp,mp2;
map<int,int>::iterator itn;

bool fun(int a,int b)
{
    if(a==b)
    {
        int a1,b1;
        itn=mp.find(a);
        a1=itn->second;
        itn=mp.find(b);
        b1=itn->second;
        return a1<b1;
    }
    else
        return a<b;
}

int main()
{
    int i,n,a,b,j,k,ctr=0,pos,save;
    cin>>n;
    int arr[n],brr[n];
    map<int,int>::iterator it,it2;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        arr[i]=a;
        brr[i]=b;
        it=mp.find(b);
        if(it!=mp.end())
        {
            if(a>it->second)
                mp[b]=a;
        }
        else
            mp[b]=a;

        it2=mp2.find(a);
        if(it2!=mp2.end())
        {
            if(b>it->second)
                mp2[a]=b;
        }
        else
            mp2[a]=b;

    }
    sort(arr,arr+n);
    sort(brr,brr+n,fun);
    map<int,int> mp1,mp22;
    for(i=0;i<n;i++)
    {
        mp1.insert(make_pair(arr[i],i));
        mp22.insert(make_pair(brr[i],i));
    }
    i=0;
    j=0;
    while(i<n && j<n)
    {
        it=mp.find(brr[i]);
        pos=it->second;
        it2=mp1.find(pos);
        k=it2->second;
        if(k>=j)
        {
            ctr++;
            j=k;
            save=arr[j];
            while(arr[j]==save)
                j++;
        }
        i=i+1;
    }
    int ctr2=0;

    i=0;
    j=0;
    while(i<n && j<n)
    {
        it=mp2.find(arr[i]);
        pos=it->second;
        it2=mp22.find(pos);
        k=it2->second;
        if(k>=j)
        {
            ctr2++;
            j=k;
            save=brr[j];
            while(brr[j]==save)
                j++;
        }
        i=i+1;
    }


    cout<<max(ctr,ctr2);
    return 0;
}
