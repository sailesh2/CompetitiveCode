#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

struct tree
{
    long long int orig;
    long long int info;
    struct tree *left;
    struct tree *right;
    struct tree *up;
};
struct tree *p,*q,*root;
struct tree *has[100005];

long long int fun(struct tree *);

int main()
{
    int i,j,n,qr,u,v;
    long long int d;
    cin>>n>>qr;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int cnt=0;
    for(i=0;i<n-1;i++)
    {
        cin>>u>>v;
        if(has[u]!=NULL)
            cnt=0;
        if(has[v]!=NULL)
            cnt=1;
        if(has[u]==NULL)
        {
            p=(struct tree*)malloc(sizeof(struct tree));
            p->info=arr[u-1];
            p->orig=p->info;
            p->left=NULL;
            p->right=NULL;
            p->up=NULL;
            has[u]=p;
        }
        if(has[v]==NULL)
        {
            p=(struct tree*)malloc(sizeof(struct tree));
            p->info=arr[v-1];
            p->left=NULL;
            p->right=NULL;
            p->up=NULL;
            has[v]=p;
        }
        p=has[u];
        q=has[v];
        if(cnt==0)
        {
            if(p->left==NULL)
                p->left=q;
            else
                p->right=q;
            q->up=p;
        }
        else
        {
            if(q->left==NULL)
                q->left=p;
            else
                q->right=p;
            p->up=q;
        }
    }
    root=has[1];
    char c;
    long long int sum=fun(root);
    for(i=0;i<qr;i++)
    {
        cin>>c;
        if(c=='Q')
        {
            cin>>u;
            cout<<has[u]->info<<"\n";
        }
        else
        {
            cin>>u>>v;
            p=has[u];
            d=v-arr[u-1];
            arr[u-1]=v;
            while(p!=NULL)
            {
                p->info=p->info+d;
                p=p->up;
            }
        }
    }
    return 0;
}

long long int fun(struct tree *s)
{
    if(s==NULL)
        return 0;
    long long int sum=fun(s->left)+fun(s->right);
    s->info=s->info+sum;
    return s->info;
}
