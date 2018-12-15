#include <stdio.h>
#include <math.h>
#include <limits.h>
#include<iostream>
#include<string.h>
#include<set>

using namespace std;

int minVal(int x, int y) { return (x < y)? x: y; }
int maxVal(int x, int y) { return (x > y)? x: y; }
int getMid(int s, int e) {  return s + (e -s)/2;  }

int mini[10000];
int maxi[10000];
int counter[10000];

void updateValueUtil( int ss, int se, int i, int ctr, int index)
{
    if (i < ss || i > se)
        return;

    if(ctr<mini[index])
        mini[index]=ctr;
    if(ctr>maxi[index])
        maxi[index]=ctr;

    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil( ss, mid, i, ctr, 2*index + 1);
        updateValueUtil( mid+1, se, i, ctr, 2*index + 2);
    }
}


int RMQMinUtil( int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        {
            return mini[index];
        }

    if (se < qs || ss > qe)
        return 10000;
    int mid = getMid(ss, se);
    int a=RMQMinUtil( ss, mid, qs, qe, 2*index+1);
    int b=RMQMinUtil( mid+1, se, qs, qe, 2*index+2);
    return minVal(a,b);
}

int RMQMin(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }

    return RMQMinUtil( 0, n-1, qs, qe, 0);
}

int RMQMaxUtil( int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        {
            return maxi[index];
        }

    if (se < qs || ss > qe)
        return -1;
    int mid = getMid(ss, se);
    int a=RMQMaxUtil( ss, mid, qs, qe, 2*index+1);
    int b=RMQMaxUtil( mid+1, se, qs, qe, 2*index+2);
    return maxVal(a,b);
}

int RMQMax(int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }

    return RMQMaxUtil( 0, n-1, qs, qe, 0);
}


set<int> constructSTUtil(int arr[], int ss, int se,  int si)
{
    int a,b;
    set<int> smans,smans2;

    if (ss == se)
    {
        int k=arr[ss];
        int ctr=0;
        int dig[10]={0};
        while(k>0)
        {
            if(dig[k%10]==0)
            {
                dig[k%10]=1;
                ctr++;
            }
            k=k/10;
        }
        counter[ctr]++;
        mini[si] = ctr;
        maxi[si]=ctr;
        set<int> st;
        st.insert(ctr);
        st.insert(ctr);
        return st;
    }

    int mid = getMid(ss, se);

    smans=constructSTUtil(arr, ss, mid, si*2+1);
    smans2=constructSTUtil(arr, mid+1, se,  si*2+2);
    set<int> st;
    set<int>::iterator it=smans.begin();
    set<int>::iterator it1=it;
    it++;
    a=minVal(*it,*it1);
    it=smans2.begin();
    it1=it;
    it++;
    b=maxVal(*it,*it1);
    mini[si]=a;
    maxi[si]=b;
    st.insert(a);
    st.insert(b);
    return st;
}

void constructST(int arr[], int n)
{
    set<int> st;
    st=constructSTUtil(arr, 0, n-1, 0);
    set<int>::iterator it=st.begin();
    mini[0]=*it;
    it++;
    maxi[0]=*it;
}

int main()
{
    int i,n,u,v,q,ans;
    string str;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    constructST(arr, n);
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>str>>u>>v;
        if(str[0]=='A')
        {
            updateValue(arr, n, u-1,(u+v)%1000000007);
        }
        else if(str[0]=='R')
        {
            updateValue(arr, n, u-1,v%1000000007);
        }
        else if(str[0]=='M' && str[1]=='U')
        {
            updateValue(arr, n, u-1,(u*v)%1000000007);
        }
        else if(str[0]=='M' && str[1]=='I')
        {
            ans=RMQMin( n, u-1, v-1);
            if(i==q-1)
                cout<<ans<<" "<<counter[ans];
            else
                cout<<ans<<" "<<counter[ans]<<"\n";
        }
        else
        {
            ans=RMQMax( n, u-1, v-1);
            if(i==q-1)
                cout<<ans<<" "<<counter[ans];
            else
                cout<<ans<<" "<<counter[ans]<<"\n";
        }
    }
    return 0;
}
