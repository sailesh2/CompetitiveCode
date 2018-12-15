#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

struct  node
{
    int val;
    int status;
    int index;
};

bool fun(struct node *a,struct node *b)
{
    return (a->val)<(b->val);
}

int main()
{
    string str;
    int i,ctr,j,cnt,n,t,start,start2;
    cin>>n;
    cin>>t;
    int has[1000]={0};
    struct node *p,*q;
    struct node *arr[2*t];
    for(i=0;i<t;i++)
    {
        cin>>str;
       // cout<<str;
        start=((int)str[0]-48)*10+(int)str[1]-48;
        if(start<8)
            start=4+start;
        else
            start=start-8;
        start=start*60+((int)str[3]-48)*10+(int)str[4]-48;
        cin>>str;
        start2=((int)str[0]-48)*10+(int)str[1]-48;
        if(start2<=8)
            start2=4+start2;
        else
        start2=start2-8;
        start2=start2*60+((int)str[3]-48)*10+(int)str[4]-48;
 //       cout<<start<<" "<<start2<<" ";
        p=(struct node *)malloc(sizeof(struct node));
        p->val=start;
        p->status=0;
        p->index=2*i;
        q=(struct node *)malloc(sizeof(struct node));
        q->val=start2;
        q->status=1;
        q->index=2*i+1;
        arr[2*i]=p;
        arr[2*i+1]=q;
    }
    //for(i=0;i<t;i++)
      //  cout<<arr[2*i]->val<<" "<<arr[2*i+1]->val<<" ";

    sort(arr,arr+2*t,fun);
    //for(i=0;i<t;i++)
      //  cout<<arr[2*i]->index<<" "<<arr[2*i+1]->index<<" ";
    ctr=0;
    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<2*t;j++)
        {
            if(has[arr[j]->index]==0)
            {
                if(cnt==0)
                {
                    if(arr[j]->status==0)
                    {
                        cnt=1-cnt;
                    }
                }
                else
                {
                    if(arr[j]->status==1)
                    {
                        cnt=1-cnt;
                        ctr++;
                        has[arr[j]->index]=1;
                        has[arr[j]->index-1]=1;
                    }
                }
            }
        }
    }
    cout<<ctr;
    return 0;
}
