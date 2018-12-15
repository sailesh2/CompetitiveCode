#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node
{
    int stat;
    int info;
    int own;
    int next;
};

bool fun(struct node a,struct node b)
{
    if(a.info==b.info)
        return a.stat<b.stat;
    else
        return a.info<b.info;
}

int main()
{
    int i,t,ctr,save,j,maxi,n,sm,a,b;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ctr=0;
        save=-1;
        maxi=0;
        sm=0;
        cin>>n;
        vector<struct node> v;
        for(j=0;j<n;j++)
        {
            cin>>a>>b;
            struct node t;
            t.stat=0;
            t.info=a;
            t.own=2*j;
            t.next=2*j+1;

            struct node t1;
            t1.stat=1;
            t1.info=b;
            t1.own=2*j+1;
            t1.next=2*j;

            v.push_back(t);
            v.push_back(t1);
        }
        int has[100001]={0};

        int other[100001]={0};


        sort(v.begin(),v.end(),fun);


        for(j=0;j<2*n;j++)
        {
            if(has[v[j].next]==0)
            {
                has[v[j].own]=j+1;
            }
            else
            {
                //cout<<j<<" "<<has[v[j].next]<<"\n";
                other[has[v[j].next]-1]=j;
                other[j]=has[v[j].next]-1;
            }
        }
        //for(j=0;j<2*n;j++)
          //  cout<<v[j].info<<" "<<v[j].stat<<"\n";

        //cout<<"ghf";
        for(j=0;j<2*n;j++)
        {
            if(v[j].stat==0)
                ctr++;
            else
                ctr--;
            if(ctr>maxi)
            {
                maxi=ctr;
                save=j;
                //cout<<"save"<<j<<" ";
            }
        }
        //cout<<maxi<<"\n";
        int select[100001]={0};
        for(j=0;j<2*n;j++)
        {
            if(v[j].stat==0)
            {
                if(v[j].info<=v[save].info && v[other[j]].info>=v[save].info)
                    select[j]=1;
            }
            else
            {
                if(v[j].info>=v[save].info && v[other[j]].info<=v[save].info)
                    select[j]=1;
            }
        }
        //cout<<save<<" ";
        sm=maxi;
        ctr=0;
        maxi=0;
        for(j=0;j<2*n;j++)
        {
            if(select[j]==0)
            {
                //cout<<j<<" ";
                if(v[j].stat==0)
                    ctr++;
                else
                    ctr--;
                if(ctr>maxi)
                {
                    maxi=ctr;
                    save=j;
                }
            }
        }
        sm=sm+maxi;
        cout<<"Case "<<i+1<<": "<<sm<<"\n";
    }
    return 0;
}
