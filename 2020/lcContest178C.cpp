/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

    bool check(ListNode* head, TreeNode* root){
        if(head==NULL)
            return true;

        if(root==NULL)
            return false;

        if(head->val != root->val)
            return false;

        return check(head->next,root->left) || check(head->next,root->right);
    }

    bool isPath(ListNode* head, TreeNode* root){
        if(root==NULL){
            return false;
        }

        if(check(head, root))
            return true;

        if(isPath(head, root->left))
            return true;

        return isPath(head,root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isPath(head, root);
    }
};
