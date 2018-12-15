#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    long long int i,n,px1,px2,py1,py2,x,y,j,saveon1=-1;
    long long int r1,r2,save;
    cin>>n>>px1>>py1>>px2>>py2;
    vector<pair<long long int,int> > one,two;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        r1=(x-px1)*(x-px1)+(y-py1)*(y-py1);
        r2=(x-px2)*(x-px2)+(y-py2)*(y-py2);
        one.push_back(make_pair(r1,i+1));
        two.push_back(make_pair(r2,i+1));

    }
    sort(one.begin(),one.end());
    sort(two.begin(),two.end());


    long long int sm=0,sm2=0;

    for(i=0;i<n;i++)
    {
        if(two[i].second == one[n-1].second)
        {
            sm=sm+two[i].first;
            save=two[i].first;
            break;
        }
    }
    for(;i<n;i++)
    {
        if(two[i].first!=save)
        {
            for(j=0;j<n;j++)
            {
                if(one[j].second==two[i].second)
                {
                    if(one[j].first<two[i].first)
                        saveon1=max(saveon1,j);
                    else
                    {
                        saveon1=-1;
                        sm=two[i].first;
                    }

                    break;
                }
            }
        }
    }
    if(saveon1>-1)
        sm=sm+one[saveon1].first;

    saveon1=-1;

    for(i=0;i<n;i++)
    {
        if(one[i].second == two[n-1].second)
        {
            sm2=sm2+one[i].first;
            save=one[i].first;
            break;
        }
    }
    for(;i<n;i++)
    {
        if(one[i].first!=save)
        {
            for(j=0;j<n;j++)
            {
                if(two[j].second==one[i].second)
                {
                    if(two[j].first<one[i].first)
                        saveon1=max(saveon1,j);
                    else
                    {
                        saveon1=-1;
                        sm2=one[i].first;
                    }
                    break;
                }
            }
        }
    }
    if(saveon1>-1)
        sm2=sm2+two[saveon1].first;

    cout<<min(sm,sm2);
    return 0;
}
