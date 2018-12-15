#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

struct tree
{
    long long int sum;
    int info;
    struct tree *left;
    struct tree *right;
    struct tree *root;
};
long double mini=100;
int save=0;
int arr[101];
void pre(struct tree *);
long long int sum_down(struct tree *);
void sum_up(long long int,struct tree *);

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
            p->sum=0;
            p->info=a;
            has[a]=p;

            q=(struct tree *)malloc(sizeof(struct tree));
            q->right=NULL;
            q->left=NULL;
            q->root=NULL;
            q->sum=0;
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
                p->sum=0;
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
                q->sum=0;
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
    //cout<<"i-"<<i<<"\n";
    head=has[i];
    //pre(head);
     head->sum=sum_down(head);
    //cout<<head->sum;
    sum_up(0,head);
    cout<<save;
    return 0;
}
void pre(struct tree *p)
{
    if(p==NULL)
        return;
    cout<<p->info<<" ";
    pre(p->left);
    pre(p->right);
}
long long int sum_down(struct tree *p)
{
    if(p==NULL)
        return 0;
    p->sum=p->sum+arr[p->info-1]+sum_down(p->left)+sum_down(p->right);
    return p->sum;
}
void sum_up(long long int sm,struct tree *p)
{
    if(p==NULL)
        return;
    p->sum=p->sum+sm+arr[p->info-1];

    //cout<<p->info<<" "<<p->sum<<"\n";
    int ctr=0;
    if(p->left!=NULL)
        ctr++;
    if(p->right!=NULL)
        ctr++;
    if(p->root!=NULL)
        ctr++;
    if((float)p->sum/ctr<mini)
    {
        mini=(float)p->sum/ctr;
        save=p->info;
    }
    sum_up(sm+arr[p->info-1],p->left);
    sum_up(sm+arr[p->info-1],p->right);
}
