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

        TreeLinkNode* curr=root;
        TreeLinkNode* prev=NULL;
        TreeLinkNode* nextLevelFirst=NULL;
        while(curr!=NULL){
            if(prev==NULL){
                if(curr->left!=NULL){
                    prev=curr->left;
                }else{
                    prev=curr->right;
                }
                if(nextLevelFirst==NULL){
                    nextLevelFirst=prev;
                }
            }else{
                if(curr->left!=NULL){
                    prev->next=curr->left;
                }else{
                    prev->next=curr->right;
                }
            }
            if(curr->left!=NULL){
                curr->left->next=curr->right;
            }
            if(prev!=NULL && prev->next!=NULL){
                prev=prev->next;
            }
            if(prev!=NULL && prev->next!=NULL){
                prev=prev->next;
            }
            curr=curr->next;
        }

        link(nextLevelFirst);
    }
public:
    void connect(TreeLinkNode *root) {
        link(root);
    }
};
