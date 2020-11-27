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
    int paths = 0;

    bool checkPseudoPalin(int* has, int nodes){
        for(int i=1;i<=9;i++){
            if(has[i]%2!=0){
                if(nodes%2==0)
                    return false;
                nodes++;
            }
        }
        return true;
    }

    void pseudoPalinPaths(TreeNode* root, int* has, int ctr){
        if(root->left==NULL && root->right==NULL){
            has[root->val]++;
            if(checkPseudoPalin(has,ctr+1))
                paths++;
            has[root->val]--;
            return;
        }

        has[root->val]++;
        if(root->left!=NULL)
        pseudoPalinPaths(root->left, has, ctr+1);
        if(root->right!=NULL)
        pseudoPalinPaths(root->right, has, ctr+1);
        has[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int has[10]={0};
        pseudoPalinPaths(root,has,0);
        return paths;
    }
};
