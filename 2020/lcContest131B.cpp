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
    int sum=0;
    void sumRootToLeaf(TreeNode* root, int v) {
        if(root->left==NULL && root->right==NULL){
            sum=sum+v*2+root->val;
            return;
        }
        if(root->left!=NULL)
        sumRootToLeaf(root->left,v*2+root->val);
        if(root->right!=NULL)
        sumRootToLeaf(root->right,v*2+root->val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return sum;
        sumRootToLeaf(root,0);
        return sum;
    }
};
