#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using namespace std;
bool fun(pair<int,long double> i,pair<int,long double> j)
{
    return (i.second)<(j.second);
}

bool fun1(pair<int,long double> i,pair<int,long double> j)
{
    return (i.first)<(j.first);
}

bool fun2(pair<int,long double> i,pair<int,long double> j)
{
    return (i.first*i.second)<(j.first*j.second);
}
int main()
{
    int i,n,t;
    long double p;
    cin>>n;
    vector< pair<int,long double> > v,v1,v2;
    for(i=0;i<n;i++)
    {
        cin>>t>>p;
        v.push_back(make_pair(t,p));
        v1.push_back(make_pair(t,p));
        v2.push_back(make_pair(t,p));
    }

    sort(v.begin(),v.end(),fun);
    sort(v1.begin(),v1.end(),fun1);
    sort(v2.begin(),v2.end(),fun2);
    vector< pair<int,long double> >::iterator it,it1;
    long double sm,pr;
    int sum;
    p=1;
    sm=0;
    for(it=v.begin();it!=v.end();it++)
    {
        sum=0;
        pr=1;
        for(it1=v.begin();it1!=it;it1++)
        {
            sum=sum+it1->first;
            pr=pr*it1->second;
        }
        sum=sum+it->first;
        pr=pr*(1-it->second);
        p=p*it->second;
        sm=sm+sum*pr;
    }
    sm=sm+(sum*p);

    p=1;
    sm1=0;
    for(it=v1.begin();it!=v1.end();it++)
    {
        sum=0;
        pr=1;
        for(it1=v1.begin();it1!=it;it1++)
        {
            sum=sum+it1->first;
            pr=pr*it1->second;
        }
        sum=sum+it->first;
        pr=pr*(1-it->second);
        p=p*it->second;
        sm1=sm1+sum*pr;
    }
    sm1=sm1+(sum*p);

    p=1;
    sm2=0;
    for(it=v2.begin();it!=v2.end();it++)
    {
        sum=0;
        pr=1;
        for(it1=v2.begin();it1!=it;it1++)
        {
            sum=sum+it1->first;
            pr=pr*it1->second;
        }
        sum=sum+it->first;
        pr=pr*(1-it->second);
        p=p*it->second;
        sm2=sm2+sum*pr;
    }
    sm2=sm2+(sum*p);

    if(sm>=sm1 && sm>=sm2)
        printf("%.8llf",sm);
    else if(sm1>=sm && sm1>=sm)
        printf("%.8llf",sm1);
    else
        printf("%.8llf",sm2);

    return 0;
}
