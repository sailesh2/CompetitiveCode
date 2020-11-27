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
    bool deleteLeaf(TreeNode* root, int target){
        if(root==NULL)
            return true;
        bool l = deleteLeaf(root->left, target);
        bool r = deleteLeaf(root->right, target);
        if(l)
            root->left=NULL;
        if(r)
            root->right=NULL;

        if(l&&r&&root->val==target)
            return true;
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(deleteLeaf(root,target))
            root=NULL;
        return root;
    }
};
