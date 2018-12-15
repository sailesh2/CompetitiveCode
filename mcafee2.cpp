#include<stdio.h>
#include<iostream>
#define gc getchar

using namespace std;

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
    int n,i,q,idx,val,sum,k=0,p,x,y,sum2;
    cin>>n;
    int arr[n];
    long long int even[n];

    for(i=0;i<n;i++)
    {
        scanint(arr[i]);
    }
    for(i=0;i<n;i++)
        even[i]=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            val=1;
            idx=i+1;
            while (idx <=n)
            {
                even[idx-1] += val;
                idx += (idx & -idx);
            }
        }
    }
    cin>>q;
    int qarr[q][3];
    int ans[q];
    for(i=0;i<q;i++)
    {
        cin>>p>>x>>y;
        qarr[i][0]=p;
        qarr[i][1]=x;
        qarr[i][2]=y;
    }
    for(i=0;i<q;i++)
    {
        p=qarr[i][0];
        x=qarr[i][1];
        y=qarr[i][2];
        if(p==0)
        {
            if(arr[x-1]%2==0)
            {
                if(y%2!=0)
                {
                    val=-1;
                    idx=x;
                    while (idx <=n)
                    {
                        even[idx-1] += val;
                        idx += (idx & -idx);
                    }
                }
                arr[x-1]=y;
            }
            else
            {
                if(y%2==0)
                {
                    val=1;
                    idx=x;
                    while (idx <=n)
                    {
                        even[idx-1] += val;
                        idx += (idx & -idx);
                    }
                }
                arr[x-1]=y;
            }
        }
        else if(p==1)
        {
            idx=y;
            sum2 = 0;
            sum=0;
            while (idx > 0)
            {
                sum2 += even[idx-1];
                idx -= (idx & -idx);
            }
            x--;
            if(x>0)
            {
                idx=x;
                while (idx > 0)
                {
                    sum += even[idx-1];
                    idx -= (idx & -idx);
                }
            }
            ans[k++]=sum2-sum;
        }
        else
        {
            idx=y;
            sum2 = 0;
            sum=0;
            while (idx > 0)
            {
                sum2 += even[idx-1];
                idx -= (idx & -idx);
            }
            x--;
            if(x>0)
            {
                idx=x;
                while (idx > 0)
                {
                    sum += even[idx-1];
                    idx -= (idx & -idx);
                }
            }
            //cout<<sum2<<" "<<sum<<"\n";
            ans[k++]=(y-x)-(sum2-sum);
        }
    }
    for(i=0;i<k;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
