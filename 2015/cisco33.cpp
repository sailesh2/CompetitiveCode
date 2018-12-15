#include<stdio.h>
#include<iostream>
#include<malloc.h>
#include<vector>
#include<string.h>
#include<map>
#include<iterator>

using namespace std;

struct trie
{
    int endnode;
    struct trie *next[26];
};


map<struct trie *,int> mp;

struct trie * fun(struct trie *,int,string,int,map<struct trie*,int>);
int fun2(struct trie *,int,string,map<struct trie *,int>,int *);

int main()
{
    int i,j,n,ctr,k;
    string str;
    while(scanf("%d",&n)!=EOF)
    {
        vector<string> v;
        struct trie *t[26];
        for(i=0;i<26;i++)
            t[i]=NULL;
        ctr=0;
        int stat[101]={0};
        for(i=0;i<n;i++)
        {
            cin>>str;
            v.push_back(str);
            if(t[str[0]-97]==NULL)
            {
                t[str[0]-97]=(struct trie *)malloc(sizeof(struct trie));
            }
            if(str.length()==1)
            {
                t[str[0]-97]->endnode=1;
                mp.insert(make_pair<struct trie*,int>((t[str[0]-97]),i+1));
            }
            else
            {
                t[str[0]-97]->endnode=0;
                t[str[0]-97]->next[str[1]-97]=fun(t[str[0]-97]->next[str[1]-97],2,str,i,mp);
            }
            cout<<i;
        }
 /*       for(i=0;i<n;i++)
        {
            str=v[i];
            k=v[i].length()-1;
            cout<<str[k]-97<<"\n";
            if(t[str[k]-97]==NULL)
            {
                continue;
            }
            else
            {
                if(fun2(t[str[k]-97],k-1,str,mp,stat)==1)
                    ctr++;
            }
       //     cout<<ctr<<"ctr\n";
        }*/
        cout<<ctr<<"\n";
    }
    return 0;
}
struct trie * fun(struct trie *p,int i,string str,int ind)
{
    cout<<i;
    if(i==str.length())
    {
        if(p==NULL)
        {
            p=(struct trie *)malloc(sizeof(struct trie));
        }
            p->endnode=1;
            mp.insert(make_pair<struct trie *,int>(p,ind+1));
            return p;
    }
    if(p==NULL)
    {
        p=(struct trie *)malloc(sizeof(struct trie));
        p->endnode=0;
    }
    cout<<str[i]-97;
    p->next[str[i]-97]=fun(p->next[str[i]-97],i+1,str,ind);
    return p;
}
int fun2(struct trie *p,int i,string str,map<struct trie *,int> mp,int *stat)
{
    //cout<<i;
    if(i==-1)
    {
        if(p->endnode==0)
        {
            int j,cnt;
            while(1)
            {
                cnt=0;
                for(j=0;j<26;j++)
                {
                    if(p->next[j]!=NULL)
                    {
                        cnt=1;
                        p=p->next[j];
                        break;
                    }
                }
                if(cnt==0)
                    break;
            }
            if(stat[(mp.find(p))->second]==0)
            {
                stat[(mp.find(p))->second]=1;
                return 1;
            }
            else
                return 0;
        }
        else
        {
            if(stat[(mp.find(p))->second]==0)
            {
                stat[(mp.find(p))->second]=1;
                return 1;
            }
            else
                return 0;
        }
    }

    if(p->next[str[i]-97]==NULL)
    {
     //   cout<<i<<" "<<str[i]-97<<"\n";
        return 0;
    }
    if(fun2(p->next[str[i]-97],i-1,str,mp,stat)==0)
        return 0;
    else
        return 1;
}
