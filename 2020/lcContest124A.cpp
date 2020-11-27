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
    int depth(TreeNode* root, int x, int h){
        if(root==NULL)
            return -1;
        if(root->val==x){
            return h;
        }
        int dl=depth(root->left,x,h+1);
        if(dl!=-1)
            return dl;
        int dr=depth(root->right,x,h+1);

        return dr;
    }

    TreeNode* parent(TreeNode* p, TreeNode* root, int x){
        if(root==NULL)
            return NULL;
        if(root->val==x){
            return p;
        }

        TreeNode *pl=parent(root, root->left, x);
        if(pl!=NULL)
            return pl;
        TreeNode *pr=parent(root, root->right, x);
        return pr;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        return depth(root, x,0) == depth(root, y,0) && parent(NULL,root, x) != parent(NULL,root, y);
    }
};
