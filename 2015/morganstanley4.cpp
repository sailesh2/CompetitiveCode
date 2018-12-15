#include<stdio.h>
#include<iostream>
#include<set>
#include<vector>

using namespace std;
int n,m,k;
long long int maxi;
int arr[100000];

void fun(int,multiset<long long int>,long long int,long long int,vector<int> *v);

int main()
{
    int i,j,u,ve,t,root;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>n>>m>>k;
        int out[100000]={0},in[100000]={0};
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        vector<int> v[n];
        for(j=0;j<n-1;j++)
        {
            cin>>u>>ve;
            out[u]++;
            in[ve]++;
            v[u].push_back(ve);
        }

        multiset<long long int> st;
        long long int local_max=-1000000000;
        for(j=0;j<n;j++)
        {
            if(arr[j]>local_max)
                local_max=arr[j];

        }
        if(local_max<=0)
            cout<<local_max<<"\n";
        else
        {
       //     cout<<root<<"\n";
            for(j=0;j<n;j++)
                fun(j,st,0,0,v);
            cout<<maxi<<"\n";
        }
    }
    return 0;
}
void fun(int i,multiset<long long int> st,long long int sum,long long int setsum,vector<int> *v)
{
    int j;

    //else
    //{
        sum=sum+arr[i];
        if(arr[i]>0 && k>0)
        {
            if(st.size()<k)
            {
                st.insert(arr[i]);
                setsum=setsum+arr[i];
            }
            else
            {
                if(st.size()>0)
                {
                if(arr[i]>*st.begin())
                {
                    setsum=setsum-*st.begin();
                    st.erase(st.begin());
                    st.insert(arr[i]);
                    setsum=setsum+arr[i];
                }
                }
                else
                {
                    st.insert(arr[i]);
                    setsum=setsum+arr[i];
                }
            }
        }
    //}

    //cout<<i<<" "<<sum<<" "<<setsum<<"\n";
    if(sum+setsum*(m-1)>maxi)
        maxi=sum+setsum*(m-1);
    for(j=0;j<v[i].size();j++)
    {
        fun(v[i][j],st,sum,setsum,v);
    }
}
