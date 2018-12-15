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
    int index;
    int endnode;
    struct trie *next[26];
};


struct trie * fun(struct trie *,int,string,int);
int fun2(struct trie *,int,string,int *);

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
                t[str[0]-97]->index=i+1;
            }
            else
            {
                t[str[0]-97]->index=i+1;
                t[str[0]-97]->endnode=0;
                t[str[0]-97]->next[str[1]-97]=fun(t[str[0]-97]->next[str[1]-97],2,str,i);
            }
 //           cout<<i;
        }
        for(i=0;i<n;i++)
        {
            if(stat[i+1]==0)
            {
                //cout<<"i------"<<i;
                stat[i+1]=1;
                str=v[i];
                k=v[i].length()-1;
                //cout<<str[k]-97<<"\n";
                if(t[str[k]-97]==NULL)
                {
                    stat[i+1]=0;
                }
                else
                {
                    if(fun2(t[str[k]-97],k-1,str,stat)==1)
                        ctr++;
                    else
                        stat[i+1]=0;
                }
            }
       //     cout<<ctr<<"ctr\n";
        }
        cout<<n-ctr<<"\n";
    }
    return 0;
}
struct trie * fun(struct trie *p,int i,string str,int ind)
{
    //cout<<i;
    if(i==str.length())
    {
        if(p==NULL)
        {
            p=(struct trie *)malloc(sizeof(struct trie));
        }
            //cout<<"in";
            p->endnode=1;
            p->index=ind+1;
            //cout<<"out";
            return p;
    }
    if(p==NULL)
    {
        p=(struct trie *)malloc(sizeof(struct trie));
        p->endnode=0;
        p->index=ind+1;
    }
    //cout<<str[i]-97;
    p->next[str[i]-97]=fun(p->next[str[i]-97],i+1,str,ind);
    return p;
}
int fun2(struct trie *p,int i,string str,int *stat)
{
    //cout<<"i"<<i;
    if(i==-1)
    {
        //if(p->endnode==0)
        {
            int j,cnt,cnt2;
            int arr[100],k=0;
            while(1)
            {
                cnt=0;
                for(j=0;j<26;j++)
                {
                    if(p->next[j]!=NULL)
                    {
                        if(p->next[j]->endnode==1)
                        {
                            p=p->next[j];
                            arr[k++]=j;
                            cnt=1;
                            //cout<<"cnt";
                            break;
                        }
                    }
                }
                if(cnt==1)
                    break;
                cnt=0;
                for(j=0;j<26;j++)
                {
                    if(p->next[j]!=NULL)
                    {
                        cnt=1;
                        p=p->next[j];
                        arr[k++]=j;
                        //cout<<"j"<<j;
                        break;
                    }
                }
                if(cnt==0)
                    break;
            }
            if(stat[p->index]==0)
            {
                cnt2=0;
                j=0;
                k--;
                while(j<=k)
                {
                    if(arr[j]!=arr[k])
                    {
                        cnt2=1;
                        break;
                    }
                    j++;
                    k--;
                }
                //cout<<"inf"<<p->index;
                if(cnt2==0)
                {
                    //cout<<"inf"<<p->index;

                    stat[p->index]=1;
                    return 1;
                }
                else
                    return 0;
            }
            else
                return 0;
        }
        /*else
        {
            if(stat[p->index]==0)
            {
                cout<<"inf"<<p->index;
                stat[p->index]=1;
                return 1;
            }
            else
                return 0;
        }*/
    }

    if(p->next[str[i]-97]==NULL)
    {
     //   cout<<i<<" "<<str[i]-97<<"\n";
        return 0;
    }
    if(fun2(p->next[str[i]-97],i-1,str,stat)==0)
        return 0;
    else
        return 1;
}
