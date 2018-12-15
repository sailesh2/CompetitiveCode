#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
    int info;
    int status;
    int cntr;
    int own;
    int ne;
};

bool fun(struct node a,struct node b)
{
    return a.info<b.info;
}

int main()
{
    int i,t,j,n,l,r,cnt,ctr;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        struct node arr[2*n];
        for(j=0;j<n;j++)
        {
            cin>>l>>r;
            arr[2*j].info=l;
            arr[2*j].status=1;
            arr[2*j].cntr=0;
            arr[2*j].own=2*j;
            arr[2*j].ne=2*j+1;

            arr[2*j+1].info=r;
            arr[2*j+1].status=0;
            arr[2*j+1].cntr=0;
            arr[2*j+1].own=2*j+1;
            arr[2*j+1].ne=2*j;
        }
        sort(arr,arr+2*n,fun);

        int has[200001];
        for(j=0;j<2*n;j++)
        {
            has[arr[j].own]=j;
        }
        for(j=0;j<2*n;j++)
            cout<<arr[j].info<<" "<<arr[j].own<<" "<<arr[j].ne<<"\n";
        /*ctr=0;
        cnt=0;
        for(j=0;j<2*n;j++)
        {
            if(cnt==0)
            {
                if(arr[j].status==1)
                {
        //            arr[j].cntr=ctr;
        //            arr[has[arr[j].next]].cntr=ctr;
                    cnt=1;
                }
            }
            else
            {
                if(arr[j].status==0 && arr[j].cntr==ctr)
                {
                    cnt=0;
                    ctr++;
                }
                else
                {
          //          arr[j].cntr=ctr;
                  //  arr[has[arr[j].next]].cntr=ctr;
                }
            }
        }
        cout<<ctr<<"\n";*/
    }
    return 0;
}
