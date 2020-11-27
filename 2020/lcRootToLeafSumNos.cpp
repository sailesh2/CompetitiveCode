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
    int sumNumbers(TreeNode* root, int prefix){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return prefix*10+root->val;
        }
        return sumNumbers(root->left, prefix*10+root->val) + sumNumbers(root->right, prefix*10+root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};
