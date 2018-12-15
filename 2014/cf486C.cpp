#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
    int n,p,i,j,l,k,ctr,len,dis1,dis2,let,cnt;
    long long int sm=0;
    string str;
    cin>>n>>p;
    cin>>str;
    i=0;
    k=0;
    let=str.length();
    int crr[let];
    j=let-1;
    p--;
    while(i<=j)
    {
        if(str[i]!=str[j])
        {
            dis1=abs(p-i);
            if(let-dis1<dis1)
                dis1=let-dis1;
            dis2=abs(p-j);
            if(let-dis2<dis2)
                dis2=let-dis2;
            if(dis1<dis2)
                crr[k++]=i;
            else
                crr[k++]=j;
        }
        i++;
        j--;
    }
    sort(crr,crr+k);
    /*l=0;
    while(l<k)
    {
        cout<<crr[l]<<" ";
        l++;
    }
    cout<<"\n";*/
    l=0;
    cnt=0;
    while(l<k)
    {
        if(crr[l]>p)
        {
            cnt=1;
            break;
        }
        l++;
    }
    if(cnt==0)
    {
        i=0;
        j=k-1;
    }
    else if(l==0)
    {
        i=0;
        j=k-1;
    }
    else
    {
        i=l-1;
        j=l;
    }
    ctr=0;
    while(ctr<k)
    {
        dis1=abs(p-crr[i]);
        if(let-dis1<dis1)
            dis1=let-dis1;

        dis2=abs(p-crr[j]);
        if(let-dis2<dis2)
            dis2=let-dis2;

        if(dis1<dis2)
        {
            sm=sm+dis1;
            p=crr[i];
            len=abs(str[p]-str[let-1-p]);
            if(26-len<len)
                len=26-len;
            //cout<<"dis1--"<<dis1<<"\n";
            //cout<<"len--"<<len<<"\n";
            sm=sm+len;
            if(i==j)
                j=(j-1)%k;
            i=(i-1)%k;
        }
        else
        {
            sm=sm+dis2;
            p=crr[j];
            len=abs(str[p]-str[let-1-p]);
            if(26-len<len)
                len=26-len;

            //cout<<"dis2--"<<dis2<<"\n";
            //cout<<"len--"<<len<<"\n";
            sm=sm+len;
            if(i==j)
                i=(i+1)%k;
            j=(j+1)%k;
        }
        ctr++;
    }
    cout<<sm;
    return 0;
}
