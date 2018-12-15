#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

long long int maxi;
long long int fun(int,vector< pair<int,int> > *,int *);

int main()
{
    int i,t,j,n,a,b,c,tot;
    cin>>t;
    for(i=0;i<t;i++)
    {
        maxi=0;
        cin>>n;
        vector< pair<int,int> > arr[100005];
        int has[100005]={0};
        for(j=0;j<n-1;j++)
        {
            cin>>a>>b>>c;
            arr[a].push_back(make_pair(b,c));

            arr[b].push_back(make_pair(a,c));
        }
        for(j=1;j<=n;j++)
        {
            for(int k=0;k<arr[j].size();k++)
            {
             //   cout<<arr[j][k].first<<" "<<arr[j][k].second;
            }
            //cout<<"\n";
        }
        has[1]=1;
        fun(1,arr,has);
        has[1]=0;
        if(maxi<=100)
            tot=0;
        else if(maxi>100 && maxi<=1000)
            tot=100;
        else if(maxi>1000 && maxi<=10000)
            tot=1000;
        else
            tot=10000;

        cout<<tot<<" "<<maxi<<"\n";
    }
    return 0;
}
long long int fun(int i,vector< pair<int,int> > *arr,int *has)
{
    int k;
    long long int l,sm=0,maxim=0;
    //cout<<i<<"\n";
    for(k=0;k<arr[i].size();k++)
    {
        if(has[arr[i][k].first]==0)
        {
            has[arr[i][k].first]=1;
            l=(long long int)(fun(arr[i][k].first,arr,has)+arr[i][k].second);
         //   cout<<l<<" ";
            if(l>maxim)
                maxim=l;
            sm=sm+l;
            has[arr[i][k].first]=0;
        }
    }
    //cout<<"\n";
    //cout<<i<<" "<<sm<<" "<<maxim<<"\n";
    if(sm>=maxi)
        maxi=sm;
    if(maxim>=maxi)
        maxi=maxim;
    return maxim;
}
