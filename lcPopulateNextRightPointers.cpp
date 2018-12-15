/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    void link(TreeLinkNode* root){
        if(root==NULL)
            return;
        if(root->next!=NULL && root->right!=NULL ){
            root->right->next=root->next->left;
        }
        if(root->left!=NULL){
            root->left->next=root->right;
        }
        link(root->left);
        link(root->right);
    }
public:
    void connect(TreeLinkNode *root) {
        link(root);
    }
};
