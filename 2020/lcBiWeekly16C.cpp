/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;
    }

    int sumH(TreeNode* root, int l, int h){
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL){
            if(l==h-1)
                return root->val;
            return 0;
        }

        return sumH(root->left,l+1,h) + sumH(root->right,l+1,h);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int h=height(root);
        return sumH(root,0,h);
    }
};
