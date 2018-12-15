#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define gc getchar


using namespace std;

struct node
{
    int info;
    int status;
    int cntr;
    int own;
    int next;
};

bool fun(struct node a,struct node b)
{
    if(a.info==b.info)
        return a.status>b.status;
    else
        return a.info<b.info;
}

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
    int i,t,j,n,l,r,cnt,ctr;
    scanint(t);
    for(i=0;i<t;i++)
    {
        scanint(n);
        struct node arr[2*n];
        for(j=0;j<n;j++)
        {
            scanint(l);
            scanint(r);
            arr[2*j].info=l;
            arr[2*j].status=1;
            arr[2*j].cntr=0;
            arr[2*j].own=2*j;
            arr[2*j].next=2*j+1;

            arr[2*j+1].info=r;
            arr[2*j+1].status=0;
            arr[2*j+1].cntr=0;
            arr[2*j+1].own=2*j+1;
            arr[2*j+1].next=2*j;
        }
        sort(arr,arr+2*n,fun);

        int has[200001],save=-1;
        for(j=0;j<2*n;j++)
        {
            has[arr[j].own]=j;
        }
        ctr=0;
        cnt=0;
        for(j=0;j<2*n;j++)
        {
            if(cnt==0 && arr[j].info!=save)
            {
                if(arr[j].status==1)
                {
                    arr[j].cntr=ctr;
                    arr[has[arr[j].next]].cntr=ctr;
                    cnt=1;
                }
            }
            else
            {
                if(arr[j].status==0 && arr[j].cntr==ctr)
                {
                    cnt=0;
                    save=arr[j].info;
                    ctr++;
                }
                else
                {
                    arr[j].cntr=ctr;
                    arr[has[arr[j].next]].cntr=ctr;
                }
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
