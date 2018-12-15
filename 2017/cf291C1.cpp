#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct trie{
    struct trie* next[3];
    int status;
};

struct trie* insertTrie(struct trie* p,int v,int endS){
    if((p->next)[v]==NULL){
        (p->next)[v]=(struct trie*)malloc(sizeof(struct trie));
        ((p->next)[v])->status=endS;
        (((p->next)[v])->next)[0]=NULL;
        (((p->next)[v])->next)[1]=NULL;
        (((p->next)[v])->next)[2]=NULL;
    } else{
        if(((p->next)[v])->status == 0){
            ((p->next)[v])->status=endS;
        }
    }
    return (p->next)[v];
}

int findTrie(struct trie* p, string s, int ind,int neglect){
    if(ind==s.length())
        return 0;
    int endS=0;
    if(ind==s.length()-1)
        endS=1;
    int ans=0,v= (int)(s[ind]-'a');
    if((p->next)[v]==NULL){
        if(endS==0){
            if(neglect==0){
                if(((p->next)[0])!=NULL){
                  ans=  findTrie((p->next)[0],s,ind+1,1);
                }
                if(ans==0 && ((p->next)[1])!=NULL){
                  ans=  findTrie((p->next)[1],s,ind+1,1);
                }
                if(ans==0 && ((p->next)[2])!=NULL){
                  ans=  findTrie((p->next)[2],s,ind+1,1);
                }
                return ans;
            } else
                return 0;
        } else{
            if(neglect==0){
                if(((p->next)[0])!=NULL){
                      ans=  ((p->next)[0])->status;
                    }
                    if(ans==0 && ((p->next)[1])!=NULL){
                      ans=  ((p->next)[1])->status;
                    }
                    if(ans==0 && ((p->next)[2])!=NULL){
                      ans=  ((p->next)[2])->status;
                    }
                    return ans;
            } else
                return 0;
        }
    } else{
        if(endS==1){
            if(((p->next)[v])->status == endS){
                return 1;
            } else{
                if(neglect==0){
                    if(((p->next)[0])!=NULL){
                      ans=  ((p->next)[0])->status;
                    }
                    if(ans==0 && ((p->next)[1])!=NULL){
                      ans=  ((p->next)[1])->status;
                    }
                    if(ans==0 && ((p->next)[2])!=NULL){
                      ans=  ((p->next)[2])->status;
                    }
                    return ans;
                } else
                    return 0;
            }
        } else{
            ans = findTrie((p->next)[v],s,ind+1,neglect);
            if(neglect==0){
                if(ans==0 && ((p->next)[0])!=NULL){
                  ans=  findTrie((p->next)[0],s,ind+1,1);
                }
                if(ans==0 && ((p->next)[1])!=NULL){
                  ans=  findTrie((p->next)[1],s,ind+1,1);
                }
                if(ans==0 && ((p->next)[2])!=NULL){
                  ans=  findTrie((p->next)[2],s,ind+1,1);
                }
            }
            return ans;
        }
    }
}

int main(){
    struct trie* root=(struct trie*)malloc(sizeof(struct trie));
    ((root)->next)[0]=NULL;
    ((root)->next)[1]=NULL;
    ((root)->next)[2]=NULL;
    ((root)->status)=0;
    int n,m,v;
    cin>>n>>m;
    string s;
    struct trie* p=root;
    for(int i=0;i<n;i++){
        cin>>s;
        p=root;
        for(int j=0;j<s.length();j++){
            v=(int)(s[j]-'a');
            if(j==s.length()-1)
                p=insertTrie(p,v,1);
            else
                p=insertTrie(p,v,0);
        }
    }
    int ans;
    for(int i=0;i<m;i++){
        cin>>s;
        p=root;
        ans=findTrie(p,s,0,0);
        if(ans==0){
            cout<<"NO\n";
        } else{
            cout<<"YES\n";
        }
    }
    return 0;
}
