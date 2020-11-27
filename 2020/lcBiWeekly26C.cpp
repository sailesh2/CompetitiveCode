/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int ctr=0;
    int MIN = -1000000;

    void good(TreeNode* node, int maxi){
        if(node==NULL){
            return;
        }

        int v= node->val;
        if(v>=maxi)
            ctr++;
        good(node->left,max(maxi,node->val));
        good(node->right,max(maxi,node->val));
    }
public:
    int goodNodes(TreeNode* root) {
        good(root,MIN);
        return ctr;
    }
};
