#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
#include<set>

using namespace std;


map<int,int> mp,mp2;
map<int,int>::iterator itn;

int main()
{
    int i,n,a,b,j,k,ctr=0,pos,save,save2;
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
            if(a<it->second)
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
    sort(brr,brr+n);
    set<int> has;
    int lenarr[100001];
    int lenarr_limit=0;
    i=0;
    while(i<n)
    {
        it=mp.find(brr[i]);
        k=it->second;
        //cout<<k<<"\n";
        if(has.find(k)==has.end())
        {
            save=0;
            save2=0;
            ctr=1;
            while(1)
            {
                save=save2;
                while(save+ctr<=lenarr_limit && lenarr[save+ctr]<k)
                {
                    save2=save+ctr;
                    ctr=ctr*2;
                }
                if(save==save2)
                    break;
                ctr=1;
            }
            if(save==lenarr_limit)
                lenarr_limit++;
            lenarr[save+1]=k;
            has.insert(k);
        }
        i++;
    }
    cout<<lenarr_limit;




    /*int ctr2=0;

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


    cout<<max(ctr,ctr2);*/
    return 0;
}
