#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int maxi;
    struct trie{
        struct trie* zero;
        struct trie* one;
    };
    int maxTrie(struct trie * root, vector<int> digs,int ind){
        if(ind==digs.size())
            return 0;
        int d=digs[ind];

        if(d==0){
            if(root->one!=NULL){
                return pow(2,digs.size()-1-ind)+maxTrie(root->one,digs,ind+1);
            }else if(root->zero!=NULL){
                return maxTrie(root->zero,digs,ind+1);
            }else{
                int sm=0;
                for(int i=ind;i<digs.size();i++){
                    sm=sm+pow(2,digs.size()-1-i)*digs[i];
                }
                return sm;
            }
        }else{
            if(root->zero!=NULL){
                return pow(2,digs.size()-1-ind)+maxTrie(root->zero,digs,ind+1);
            }else if(root->one!=NULL){
                return maxTrie(root->one,digs,ind+1);
            }else{
                int sm=0;
                for(int i=ind;i<digs.size();i++){
                    sm=sm+pow(2,digs.size()-1-i)*digs[i];
                }
                return sm;
            }
        }
    }
    void insertTrie(struct trie * root, vector<int> digs,int ind){
        if(ind==digs.size())
            return;
        int d=digs[ind];
        if(d==0){
            if(root->zero==NULL){
                struct trie *p=(struct trie*)malloc(sizeof(struct trie));
                p->zero=NULL;
                p->one=NULL;
                root->zero=p;
            }
            insertTrie(root->zero,digs,ind+1);
        }else{
             if(root->one==NULL){
                struct trie *p=(struct trie*)malloc(sizeof(struct trie));
                p->zero=NULL;
                p->one=NULL;
                root->one=p;
            }
            insertTrie(root->one,digs,ind+1);
        }
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi=0;
        struct trie * root = (struct trie*)malloc(sizeof(struct trie));
        root->one=NULL;
        root->zero=NULL;

        vector<int> digs;
        vector<int> temp;
        int v,ctr;
        for(int i=0;i<nums.size();i++){
            temp.clear();
            v=nums[i];
            ctr=0;
            while(v>0){
                temp.push_back(v%2);
                v=v/2;
                ctr++;
            }
            while(ctr<32){
                temp.push_back(0);
                ctr++;
            }
            digs=temp;
            for(int j=0;j<temp.size();j++)
                digs[j]=temp[temp.size()-1-j];
            if(i>0){
                v=maxTrie(root,digs,0);
                maxi=max(maxi,v);
            }
            insertTrie(root,digs,0);
        }
        return maxi;
    }
};


int main(){
    Solution sol;
    vector<int> a;
    a.push_back(8);
    a.push_back(10);
    a.push_back(2);
    cout<<sol.findMaximumXOR(a);
    return 0;
}
