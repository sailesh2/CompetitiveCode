#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;

struct node
{
    int info;
    struct node *down;
    struct node *right;
    int flag;
};
int n,mini;
struct node *t[100001],*p,*q;
void fun(int,int,int *);
int main()
{
    int i,m,x,y;
    cin>>n>>m;
    int sav[n+1];
    sav[0]=0;
    for(i=1;i<=n;i++)
    {
        sav[i]=0;
        t[i]=(struct node *)malloc(sizeof(struct node));
        t[i]->info=i;
        t[i]->flag=1;
        t[i]->right=NULL;
        t[i]->down=NULL;
        if(i>1)
            t[i-1]->down=t[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        p=(struct node *)malloc(sizeof(struct node));
        p->right=NULL;
        p->down=NULL;
        p->info=y;
        p->flag=1;
        q=t[x]->right;
        t[x]->right=p;
        p->right=q;

        p=(struct node *)malloc(sizeof(struct node));
        p->right=NULL;
        p->down=NULL;
        p->info=x;
        p->flag=0;
        q=t[y]->right;
        t[y]->right=p;
        p->right=q;
    }
    mini=1000000;
    fun(1,0,sav);
    cout<<mini;
    return 0;
}

int fun(int i,int ctr,int *sav)
{
    if(t[i]->info==n)
    {
        if(ctr<=mini)
            mini=ctr;
        return ctr;
    }
    struct node *k=t[i]->right;
  //  cout<<k->info;
    while(k!=NULL)
    {
        if(sav[k->info]==0)
        {

            sav[k->info]=1;
            if(k->flag==0)
                {
      //              cout<<k->info;
                    a=fun(k->info,ctr+1,sav);
                }
            else
                a=fun(k->info,ctr,sav);
            if(a-ctr<=minimum)
                minimum=a-ctr;
            sav[k->info]=0;
        }
        //cout<<k->info<<"sf";
        k=k->right;
    }
}
