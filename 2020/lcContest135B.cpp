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
    int bstToGst(TreeNode* root, int parentValue){
        if(root==NULL){
            return 0;
        }
        int origVal = root->val;
        int childValueR = bstToGst(root->right,parentValue);
        root->val = childValueR + parentValue + origVal;
        int childValueL = bstToGst(root->left,root->val);
        return childValueR + childValueL + origVal;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        bstToGst(root,0);
        return root;
    }
};
