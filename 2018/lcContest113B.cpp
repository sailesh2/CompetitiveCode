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
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1==NULL){
            return false;
        }
        if(root2==NULL){
            return false;
        }

        return root1->val == root2->val;
    }

    bool isFlipPossible(TreeNode* root1, TreeNode* root2){
        return (isSame(root1->left,root2->left) && isSame(root1->right,root2->right))
        ||  (isSame(root1->left,root2->right) && isSame(root1->right,root2->left));
    }

    void flipNode(TreeNode* root1, TreeNode* root2){
        if( !(isSame(root1->left,root2->left) && isSame(root1->right,root2->right))){
            TreeNode* tmp = root1->left;
            root1->left=root1->right;
            root1->right=tmp;
         }
    }

    bool flip(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL){
            return false;
        }
        if(root2==NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        if(isFlipPossible(root1,root2)){
            flipNode(root1,root2);
            return flip(root1->left, root2->left) && flip(root1->right, root2->right);
        }
        return false;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return flip(root1,root2);
    }
};
