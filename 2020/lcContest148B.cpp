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

    TreeNode* findNode(TreeNode* root, int x){
        if(root==NULL)
            return NULL;

        if(root->val==x)
            return root;

        TreeNode* ln = findNode(root->left,x);
        if(ln!=NULL)
            return ln;

        TreeNode* rn = findNode(root->right,x);
        if(rn!=NULL)
            return rn;

        return NULL;
    }

    int subTreeCount(TreeNode* root){
        if(root==NULL)
            return 0;
        return subTreeCount(root->left) + subTreeCount(root->right) + 1;
    }

    bool canWin(TreeNode* root, int n, int x){
        TreeNode* node = findNode(root, x);
        int subCntP = subTreeCount(node);
        bool p = n-subCntP>subCntP;

        int subCntL = subTreeCount(node->left);
        bool cl = subCntL>n-subCntL;

        int subCntR = subTreeCount(node->right);
        bool cr = subCntR>n-subCntR;

        return p || cl || cr;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        return canWin(root, n, x);
    }
};
