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
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        else if(left!=NULL && right !=NULL){
            if(left->val==right->val){
                return (isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left));
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetric(root->left,root->right);
    }
};
