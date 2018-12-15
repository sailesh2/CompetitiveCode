/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> in;
    void minDist(TreeNode* root){
        if(root==NULL)
            return;
        minDist(root->left);
        in.push_back(root->val);
        minDist(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        minDist(root);
        int mini=1000000000;
        if(in.size()==0)
            return 0;
        else if(in.size()==1)
            return in[0];
        else{
            for(int i=1;i<in.size();i++){
                mini=min(mini,abs(in[i]-in[i-1]));
            }
            return mini;
        }
    }
};
