#include<bits/stdc++.h>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> lar;
        int ctr=1,maxi=0,tempCtr=0;
        vector<TreeNode*> tree;
        tree.push_back(root);
        vector<TreeNode*> tempTree;
        while(1){
            for(int i=0;i<ctr;i++){
                maxi=max(maxi,tree[i]->val);
                if(tree[i]->left!=NULL){
                    tempTree.push_back(tree[i]->left);
                    tempCtr++;
                }
                if(tree[i]->right!=NULL){
                    tempTree.push_back(tree[i]->right);
                    tempCtr++;
                }
            }
            ctr=tempCtr;
            tempCtr=0;
            tree=tempTree;
            tempTree.clear();
            lar.push_back(maxi);
            maxi=0;
            if(ctr==0)
                break;
        }
        return lar;
    }
};
int main(){
    return 0;
}
