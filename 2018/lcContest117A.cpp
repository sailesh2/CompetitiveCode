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
    int val=-1;

    bool isUniValue(TreeNode* root){
        if(root==NULL)
            return true;
        if(val==-1)
            val=root->val;
        else if(root->val != val)
            return false;

        return isUniValue(root->left) && isUniValue(root->right);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        return isUniValue(root);
    }
};
