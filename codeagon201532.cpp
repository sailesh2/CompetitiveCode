#include<iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include<algorithm>
#include <utility>

using namespace std;

int cnt[1000000];

int middle(int s, int e) {  return s + (e -s)/2;  }

pair<int,int> range_max(int *st, int ss, int se, int qs, int qe, int index)
{
    int glcnt;
    if (qs <= ss && qe >= se)
    {
        glcnt=cnt[index];
        pair<int,int> p=make_pair(st[index],glcnt);
        return p;
    }

    if (se < qs || ss > qe)
    {
        glcnt=0;
        return make_pair(INT_MIN,0);
    }

    int mid = middle(ss, se);

    pair<int,int> p1=range_max(st, ss, mid, qs, qe, 2*index+1);
    pair<int,int> p2=range_max(st, mid+1, se, qs, qe, 2*index+2);
    int var1=p1.first;
    int cnt1=p1.second;
    int var2=p2.first;
    int cnt2=p2.second;
    if(var1==var2)
        glcnt=cnt1+cnt2;
    else if(var1>var2)
        glcnt=cnt1;
    else
        glcnt=cnt2;
    //cout<<glcnt<<" "<<" index  "<<ss<<" "<<se<<"\n";
    pair<int,int> p=make_pair(max(var1,var2),glcnt);
    return p;
}

pair<int,int> range(int *st, int n, int qs, int qe)
{


    return range_max(st, 0, n-1, qs, qe, 0);
}

int built(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        cnt[si]=1;
        return arr[ss];
    }

    int mid = middle(ss, se);
    int var1=built(arr, ss, mid, st, si*2+1);
    int var2=built(arr, mid+1, se, st, si*2+2);
    st[si]=max(var1,var2);
    if(var1==var2)
        cnt[si]=cnt[si*2+1]+cnt[si*2+2];
    else if(var1>var2)
        cnt[si]=cnt[si*2+1];
    else
        cnt[si]=cnt[si*2+2];
    //cout<<cnt[si]<<" ";
    return st[si];
}

int *seg(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];


    built(arr, 0, n-1, st, 0);

    return st;
}

int main()
{
    int i,n,m;
    cin>>n>>m;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        cnt[i]=0;
    }
    int *st = seg(arr, n);
    int qs;
    int qe;

    for(i=0;i<m;i++)
    {
        //glcnt=0;
        cin>>qs>>qe;
        pair<int,int> p=range(st, n, qs-1, qe-1);
        cout<<p.second<<"\n";
    }
    return 0;
}
