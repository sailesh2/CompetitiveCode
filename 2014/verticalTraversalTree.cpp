#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
};
int mini=1000000,maxi=0,top=-1;
int ans[1000][10];
int ctr[1000]={0};
struct tree * stacki[100];

void push(struct tree *);
struct tree * pop();
void ver(struct tree *);
void in(struct tree *);

int main()
{
    int i,c,j,data;
    struct tree *root=(struct tree *)malloc(sizeof(struct tree));
    root->left=root->right=NULL;
    cout<<"enter data\n";
    cin>>root->info;
    struct tree *p,*q;
    p=root;
    while(p!=NULL)
    {
        cout<<"want "<<p->info<<" left child  1--yes  2--no\n";
        cin>>c;
        if(c==1)
        {
            q=(struct tree *)malloc(sizeof(struct tree));
            q->left=q->right=NULL;
            cout<<"enter data\n";
            cin>>q->info;
            p->left=q;
        }
        cout<<"want "<<p->info<<" right child  1--yes  2--no\n";
        cin>>c;
        if(c==1)
        {
            q=(struct tree *)malloc(sizeof(struct tree));
            q->left=q->right=NULL;
            cout<<"enter data\n";
            cin>>q->info;
            p->right=q;
            push(q);
        }
        p=p->left;
        if(p==NULL)
            p=pop();
    }
    in(root);
    ver(root);

    cout<<"\n";
    for(i=mini;i<=maxi;i++)
    {
        for(j=0;j<ctr[500+i];j++)
            cout<<ans[500+i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
void push(struct tree *p)
{
    stacki[++top]=p;
}
struct tree * pop()
{
    if(top==-1)
        return NULL;
    return stacki[top--];
}
void in(struct tree *p)
{
    if(p==NULL)
        return;
    in(p->left);
    cout<<p->info<<" ";
    in(p->right);
}
void ver(struct tree *p)
{
    int k=0;
    struct tree * que1[100];
    int que2[100];
    int rear=-1,fronti=-1;
    fronti++;
    que1[++rear]=p;
    que2[rear]=0;
    ans[500][ctr[500]++]=p->info;
    k=rear+1;
    while(1)
    {
        while(fronti<=rear)
        {
            p=que1[fronti];
            if(p->left!=NULL)
            {
                que1[k]=p->left;
                que2[k]=que2[fronti]-1;
                if(que2[k]<=mini)
                    mini=que2[k];
                ans[500+que2[k]][ctr[500+que2[k]]++]=que1[k]->info;
                k++;
            }
            if(p->right!=NULL)
            {
                que1[k]=p->right;
                que2[k]=que2[fronti]+1;
                if(que2[k]>=maxi)
                    maxi=que2[k];
                ans[500+que2[k]][ctr[500+que2[k]]++]=que1[k]->info;
                k++;
            }
            fronti++;
        }
        if(k==rear+1)
            break;
        rear=k-1;
    }
}
