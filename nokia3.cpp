#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int i,n,j,q,val,ctr,mod=1000000007;
    cin>>n;
    int arr[n],brr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    cin>>q;
    int l=4001;
    int arra[4001]={0};
    arra[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=l-1;j>=0;j--)
        {
            if(arra[j]>0)
            {
                arra[j+arr[i]] =(arra[j+arr[i]]+1)%mod;
            }
        }
    }
    int sum_arr[4001];
    int arrb[4001]={0},sm=0;
    int k=0;
    for(i=0;i<l;i++)
    {
        if(arra[i]>0)
        {
            arrb[k]=i;
            sm=(sm+arra[i])%mod;
            sum_arr[k]=sm;
            k++;
        }
    }

    int brra[4001]={0};
    brra[0]=1;
    for(i=0;i<n;i++)
    {
        for(j=l-1;j>=0;j--)
        {
            if(brra[j]>0)
            {
               brra[j+brr[i]]= (brra[j+brr[i]]+1)%mod;
            }
        }
    }

    int sum_brr[4001];
    int brrb[4001]={0};
    sm=0;
    int k1=0,save,save2;
    for(i=0;i<l;i++)
    {
        if(brra[i]>0)
        {
            brrb[k1]=i;
            sm=(sm+brra[i])%mod;
            sum_brr[k1]=sm;
            k1++;
        }
    }
    i=0;
    j=0;
    sm=0;
    while(i<k && j<k1)
    {
        while(i<k && j<k1)
        {
            if(brrb[j]-arrb[i]<=q)
                break;
            if(brrb[j]-arrb[i]>q)
                i++;
            else
                j++;
        }
        if(i>=k || j>=k1)
            break;
        val=brrb[j];
        ctr=0;
        save=i-1;
        save2=i-1;
        while(1)
        {
            save=save2;
            ctr=1;
            while(save+ctr<k && abs(val-arrb[save+ctr])<=q)
            {
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2)
                break;
        }
        cout<<save<<" "<<i<<"\n";
        if(i==0)
            sm=(sm+sum_arr[save])%mod;
        else
            sm=(sm+sum_arr[save]-sum_arr[i-1])%mod;

    j++;
    }
    cout<<sm;
    return 0;
}
