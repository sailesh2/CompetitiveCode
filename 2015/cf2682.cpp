#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int i,p,q,l,r,j,k,ctr=0,a,b,c,d,dif,op,cl;
    cin>>p>>q>>l>>r;
    int prr[p][2],qrr[q][2];
    for(i=0;i<p;i++)
    {
        cin>>prr[i][0]>>prr[i][1];
    }
    for(i=0;i<q;i++)
    {
        cin>>qrr[i][0]>>qrr[i][1];
    }
    int arr[10000]={0};
    for(i=0;i<p;i++)
    {
        a=prr[i][0];
        b=prr[i][1];
        for(j=0;j<q;j++)
        {
            c=qrr[j][0];
            d=qrr[j][1];
            dif=d-c;
            op=max(a-dif-c,l);
            cl=min(r,b-c);
            for(k=op;k<=cl;k++)
                arr[k]=1;
        }
    }
    for(i=l;i<=r;i++)
    {
        if(arr[i]==1)
            ctr++;
    }
    cout<<ctr;
    return 0;
}
