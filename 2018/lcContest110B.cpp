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
    int sum=0;

    void rangeSumTree(TreeNode* root, int L, int R){
        if(root==NULL)
            return;
        if(root->val >=L && root->val <=R)
            sum=sum+root->val;
        rangeSumTree(root->left,L,R);
        rangeSumTree(root->right,L,R);
    }

public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        rangeSumTree(root, L, R);
        return sum;
    }
};
