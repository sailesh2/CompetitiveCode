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
    TreeNode* trim(TreeNode* root, int L, int R){
        if(root==NULL)
            return NULL;

        if(root->val<L){
            root=trim(root->right,L,R);
        }else if(root->val>R){
            root=trim(root->left,L,R);;
        }else{
            root->left=trim(root->left,L,R);
            root->right=trim(root->right,L,R);
        }

        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        return trim(root,L,R);
    }
};
