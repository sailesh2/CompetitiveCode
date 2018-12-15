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
    int maxi=-100000000;
    int maxSum(TreeNode* root){
        if(root==NULL)
            return 0;
        int a=maxSum(root->left);
        int b=maxSum(root->right);
        int v=max(root->val,max(a+root->val,b+root->val));
        maxi=max(maxi,max(v,a+b+root->val));
        return v;
    }
public:
    int maxPathSum(TreeNode* root) {
        int x=maxSum(root);
        return maxi;
    }
};
