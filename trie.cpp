#include<stdio.h>
#include<iostream>
#include<string.h>
#include<malloc.h>

using namespace std;

struct triee
{
    struct triee * crr[26];
};

string s;
int ctr,stat;

void get(struct triee *,int);

int main()
{
    struct triee *root[26]={NULL};
    int i,t,j,k,n,sm;
    cin>>t;
    for(i=0;i<t;i++)
    {
        sm=0;
        cin>>n;
        for(k=0;k<26;k++)
            root[k]=NULL;
        for(j=0;j<n;j++)
        {
            ctr=0;
            stat=0;
            cin>>s;
            if(root[(int)s[0]-97]==NULL)
            {
                struct triee *p=(struct triee *)malloc(sizeof(struct triee));
                if(stat==0)
                {
                    ctr++;
                    stat=1;
                }
                for(k=0;k<26;k++)
                    p->crr[k]=NULL;

                root[(int)s[0]-97]=p;

            }
            else
            {
                if(stat==0)
                    ctr++;
            }
            get(root[(int)s[0]-97],1);
            //cout<<ctr<<"\n";
            sm=sm+ctr;
        }
        cout<<"Case #"<<i+1<<": "<<sm<<"\n";
    }
    return 0;
}

void get(struct triee *p,int i)
{
    int j;
    if(i==s.length())
        return;
    if(p->crr[(int)s[i]-97]==NULL)
    {
        struct triee *q=(struct triee *)malloc(sizeof(struct triee));

        if(stat==0)
        {
            ctr++;
            stat=1;
        }
        for(j=0;j<26;j++)
            q->crr[j]=NULL;
        p->crr[(int)s[i]-97]=q;

    }
    else
    {
        if(stat==0)
            ctr++;
    }
    get(p->crr[(int)s[i]-97],i+1);
}
