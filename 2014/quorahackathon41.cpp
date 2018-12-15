#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

struct tree
{
    long long int left_sum;
    long long int right_sum;
    long long int left_cnt;
    long long int right_cnt;
    int info;
    struct tree *left;
    struct tree *right;
    struct tree *root;
};
int arr[101];
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
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        if(has[a]==NULL && has[b]==NULL)
        {
            p=(struct tree *)malloc(sizeof(struct tree));
            p->right=NULL;
            p->left=NULL;
            p->root=NULL;
            p->left_sum=0;
            p->right_sum=0;
            p->left_cnt=0;
            p->right_cnt=0;
            p->info=a;
            has[a]=p;

            q=(struct tree *)malloc(sizeof(struct tree));
            q->right=NULL;
            q->left=NULL;
            q->root=NULL;
            q->left_sum=0;
            q->right_sum=0;
            q->left_cnt=0;
            q->right_cnt=0;
            q->info=b;
            has[b]=q;

            p->left=q;
            q->root=p;
        }
        else if(has[a]!=NULL && has[b]!=NULL)
        {
            p=has[a];
            q=has[b];
            if(q->root==NULL && (p->left==NULL || p->right==NULL))
            {
                if(p->left==NULL)
                {
                    p->left=q;
                    q->root=p;
                }
                else
                {
                    p->right=q;
                    q->root=p;
                }
            }
            else if(p->root==NULL && (q->left==NULL || q->right==NULL))
            {
                if(q->left==NULL)
                {
                    q->left=p;
                    p->root=q;
                }
                else
                {
                    q->right=p;
                    p->root=q;
                }
            }
        }
        else
        {
            if(has[a]==NULL)
            {
                p=(struct tree *)malloc(sizeof(struct tree));
                p->left=NULL;
                p->right=NULL;
                p->root=NULL;
                p->left_sum=0;
                p->right_sum=0;
                p->left_cnt=0;
                p->right_cnt=0;
                p->info=a;
                has[a]=p;

                q=has[b];
                if(q->left==NULL)
                {
                    q->left=p;
                    p->root=q;
                }
                else if(q->right==NULL)
                {
                    q->right=p;
                    p->root=q;
                }
                else
                {
                    p->left=q;
                    q->root=p;
                }
            }
            else
            {
                q=(struct tree *)malloc(sizeof(struct tree));
                q->left=NULL;
                q->right=NULL;
                q->root=NULL;
                q->left_sum=0;
                q->right_sum=0;
                q->left_cnt=0;
                q->right_cnt=0;
                q->info=b;
                has[b]=q;

                p=has[a];
                if(p->left==NULL)
                {
                    p->left=q;
                    q->root=p;
                }
                else if(p->right==NULL)
                {
                    p->right=q;
                    q->root=p;
                }
                else
                {
                    q->left=p;
                    p->root=q;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(has[i]->root==NULL)
            break;
    }
    head=has[i];
    down_op(head);
    for(i=1;i<=n;i++)
    {
        p=has[i];
        //cout<<p->left_cnt<<" "<<p->right_cnt<<" "<<p->left_sum<<" "<<p->right_sum<<"\n";
    }
    up_op(head,make_pair(0,0));
    cout<<save;
    return 0;
}
pair<long long int,long long int> down_op(struct tree *p)
{
    pair<long long int,long long int> pr,pr1;
    if(p==NULL)
    {
        pr=make_pair(0,0);
        return pr;
    }
    pr1=down_op(p->left);
    p->left_sum=pr1.first;
    p->left_cnt=pr1.second;
    pr1=down_op(p->right);
    p->right_sum=pr1.first;
    p->right_cnt=pr1.second;
    int cnt=p->left_cnt+p->right_cnt;
    if(cnt==0)
        cnt=1;
    pr=make_pair(p->left_sum+p->right_sum+cnt*arr[p->info-1],cnt);
    return pr;
}
void up_op(struct tree *p,pair<long long int,long long int> pr)
{
    if(p==NULL)
        return;
    long long int sm=pr.first;
    long long int ctr=pr.second;
    ctr=ctr+p->left_cnt+p->right_cnt;
    if(ctr==0)
        ctr=1;
    sm=sm+p->left_sum+p->right_sum+ctr*arr[p->info-1];
    if((long double)sm/ctr<mini)
    {
        mini=(long double)sm/ctr;
        save=p->info;
    }
    //cout<<p->info<<" "<<sm<<" "<<ctr<<"\n";
    pair<long long int,long long int> pr1;
    ctr=pr.second+p->right_cnt;
    if(ctr==0)
        ctr=1;
    pr1=make_pair(pr.first+p->right_sum+ctr*arr[p->info-1],ctr);
    up_op(p->left,pr1);
    ctr=pr.second+p->left_cnt;
    if(ctr==0)
        ctr=1;
    pr1=make_pair(pr.first+p->left_sum+ctr*arr[p->info-1],ctr);
    up_op(p->right,pr1);
}
