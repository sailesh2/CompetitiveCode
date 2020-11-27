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
    TreeNode* sufficientTree(TreeNode* root, int sum, int limit){
        if(root==NULL)
        return NULL;
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val<limit)
                return NULL;
            else
                return root;
        }
        int v=root->val;
        sum=sum+v;
        root->left = sufficientTree(root->left, sum, limit);
        root->right = sufficientTree(root->right, sum, limit);

        if(root->left==NULL && root->right==NULL)
            return NULL;
        return root;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return sufficientTree(root,0,limit);
    }
};
