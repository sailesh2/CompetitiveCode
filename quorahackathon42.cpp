#include<stdio.h>
#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

struct tree
{
    int info;
    vector<struct tree *> next;
    vector<long long int> sum;
    vector<long long int> cnt;
    long long int tot_sum;
    long long int tot_cnt;
};
int arr[101];
int vis[101]={0};
int vis1[101]={0};
long double mini=1000;
int save;
pair<long long int,long long int> down_op(struct tree *);
void up_op(struct tree *,pair<long long int,long long int>);


int main()
{
    int i,n,a,b;
    cin>>n;
    struct tree *p,*q,*head;
    struct tree * has[101]={NULL};
    vector<struct tree *> v;
    vector<long long int> v1,v2;
    vector<struct tree *>::iterator it;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        //cout<<i<<"\n";
        cin>>a>>b;
        if(has[a]==NULL && has[b]==NULL)
        {
            p=new struct tree;
            p->sum.push_back(0);
            p->cnt.push_back(0);
            p->tot_sum=0;
            p->tot_cnt=0;
            p->info=a;
            has[a]=p;

            q=new struct tree;
            q->sum.push_back(0);
            q->cnt.push_back(0);
            q->tot_sum=0;
            q->tot_cnt=0;
            q->info=b;
            has[b]=q;

            p->next.push_back(q);
            q->next.push_back(p);
        }
        else if(has[a]!=NULL && has[b]!=NULL)
        {
            p=has[a];
            q=has[b];
            p->sum.push_back(0);
            p->cnt.push_back(0);
            q->sum.push_back(0);
            q->cnt.push_back(0);
            p->next.push_back(q);
            q->next.push_back(p);
        }
        else
        {
            if(has[a]==NULL)
            {
                p=new struct tree;
                p->sum.push_back(0);
                p->cnt.push_back(0);
                p->tot_sum=0;
                p->tot_cnt=0;
                p->info=a;
                has[a]=p;

                q=has[b];
                q->sum.push_back(0);
                q->cnt.push_back(0);
                p->next.push_back(q);
                q->next.push_back(p);
            }
            else
            {
                q=new struct tree;
                q->sum.push_back(0);
                q->cnt.push_back(0);
                q->tot_sum=0;
                q->tot_cnt=0;
                q->info=b;
                has[b]=q;

                p=has[a];
                p->sum.push_back(0);
                p->cnt.push_back(0);
                q->next.push_back(p);
                p->next.push_back(q);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        p=has[i];
        cout<<"\n"<<i<<"\n";
        v=p->next;
        for(it=v.begin();it!=v.end();it++)
            cout<<(*it)->info<<" ";
    }*/
    head=has[1];

    down_op(head);
    /*int j;
    for(i=1;i<=n;i++)
    {
        p=has[i];
        cout<<p->info<<" "<<p->tot_sum<<" "<<p->tot_cnt<<"\n";
        j=0;
        v=p->next;
        v1=p->sum;
        v2=p->cnt;
        for(j=0;j<v.size();j++)
        {
            cout<<v[j]->info<<" "<<v1[j]<<" "<<v2[j]<<"\n";
        }
    }*/

    up_op(head,make_pair(0,0));
    cout<<save;

    return 0;
}
pair<long long int,long long int> down_op(struct tree *p)
{
    vis[p->info]=1;
    pair<long long int,long long int> pr;
    vector<struct tree *> v=p->next;
    long long int sm=0,ctr=0;
    int i;
    for(i=0;i<v.size();i++)
    {
        if(vis[(v[i])->info]==0)
        {
            pr=down_op(v[i]);

            p->sum[i]=pr.first;
            p->cnt[i]=pr.second;
            //cout<<v[i]->info<<" "<<v1[i]<<" "<<v2[i]<<"\n";
            sm=sm+pr.first;
            ctr=ctr+pr.second;
        }
    }
    p->tot_sum=sm;
    p->tot_cnt=ctr;
    vis[p->info]=0;
    if(ctr==0)
        ctr=1;
    pr=make_pair(sm+ctr*arr[p->info-1],ctr);
    return pr;
}
void up_op(struct tree *p,pair<long long int,long long int> pr)
{
    vis1[p->info]=1;
    long long int sm=pr.first;
    long long int ctr=pr.second;
    sm=sm+p->tot_sum;
    ctr=ctr+p->tot_cnt;
    if(ctr==0)
        ctr=1;
    //cout<<p->info<<" "<<sm+ctr*arr[p->info-1]<<" "<<ctr<<"\n";
    if((long double)(sm+ctr*arr[p->info-1])/ctr<mini)
    {
        mini=(long double)(sm+ctr*arr[p->info-1])/ctr;
        save=p->info;
    }
    vector<struct tree *> v=p->next;
    vector<long long int> v1=p->sum;
    vector<long long int> v2=p->cnt;

    pair<long long int,long long int> pr1;
    int i;
    for(i=0;i<v.size();i++)
    {
        if(vis1[v[i]->info]==0)
        {
            //cout<<v[i]->info<<" "<<v1[i]<<" "<<v2[i]<<"\n";
            ctr=pr.second+p->tot_cnt-v2[i];
            if(ctr==0)
                ctr=1;
            sm=pr.first+p->tot_sum-v1[i]+ctr*arr[p->info-1];
            pr1=make_pair(sm,ctr);
            up_op(v[i],pr1);
        }
    }
    vis1[p->info]=0;
}
