
#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int,int> freq;
    map<int,int>::iterator freqIt;
    vector<int> fl[100000];
    int maxi=-1;
    int frequentTreeSum(TreeNode* root){
        if(root==NULL)
            return 0;
        int lval=frequentTreeSum(root->left);
        int rval=frequentTreeSum(root->right);
        int s=lval+rval+root->val;
        freqIt=freq.find(s);
        int f;
        if(freqIt==freq.end()){
            f=1;
        }else{
            f=freqIt->second+1;
            freq.erase(freqIt);
        }
        freq.insert(make_pair(s,f));

        if(f>=maxi){
            maxi=f;
            fl[f].push_back(s);
        }
        return s;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        frequentTreeSum(root);
        vector<int> d;
        return maxi<0?d:fl[maxi];
    }
};
