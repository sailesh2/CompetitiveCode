#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,x,m,i,q,j,sum,idx,val,n0,m0,m1,p0;
    cin>>n>>m>>q;
    int arr[100005]={0},brr[n];
    for(i=0;i<n;i++)
    {
        cin>>x;
        arr[x]++;
        brr[i]=x;
    }


    int ans[100005]={0};
    for(i=0;i<n;i++)
    {
        idx=arr[i]+1;
        val=1;
        while (idx <=n+1)
        {
            ans[idx-1] = ans[idx-1] + val;
            idx += (idx & -idx);
        }
    }

    for(i=0;i<q;i++)
    {
        cin>>x;
        if(x==1)
        {
            cin>>n0>>m1;
            m0=brr[n0];
            brr[n0]=m1;

            idx=arr[m0]+1;
            val=-1;
            while (idx>0 && idx <=n+1)
            {
                ans[idx-1] = ans[idx-1] + val;
                idx += (idx & -idx);
            }
            arr[m0]--;
            idx=arr[m0]+1;
            val=1;
            while (idx>0 && idx <=n+1)
            {
                ans[idx-1] = ans[idx-1] + val;
                idx += (idx & -idx);
            }




            idx=arr[m1]+1;
            val=-1;
            while (idx>0 && idx <=n+1)
            {
                ans[idx-1] = ans[idx-1] + val;
                idx += (idx & -idx);
            }
            arr[m1]++;
            idx=arr[m1]+1;
            val=1;
            while (idx>0 && idx <=n+1)
            {
                ans[idx-1] = ans[idx-1] + val;
                idx += (idx & -idx);
            }
        }
        else
        {
            cin>>p0;
            sum = 0;
            idx=p0;
           // cout<<idx;
            while(idx > 0)
            {
                sum = (sum + ans[idx-1]);
                idx -= (idx & -idx);
            }
            cout<<sum<<"\n";
        }

    }

}
