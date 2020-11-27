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
    pair<TreeNode*, int> lcaDeepLeaf(TreeNode* root, int h){
        if(root==NULL){
            return make_pair(root,h);
        }

        pair<TreeNode*,int> leftDepth = lcaDeepLeaf(root->left,h+1);
        pair<TreeNode*,int> rightDepth = lcaDeepLeaf(root->right,h+1);

        int hl=leftDepth.second;
        int hr=rightDepth.second;


        if(hl==hr){
            return make_pair(root,hl);
        }else if(hl>hr){
            return make_pair(leftDepth.first,hl);
        }else{
            return make_pair(rightDepth.first,hr);
        }

    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepLeaf(root,0).first;
    }
};
