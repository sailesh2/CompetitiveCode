/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(long long int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    long long int maxi=0;
    long long int sum=0;
    long long int mod=1000000007;

    long long int sumTree(TreeNode* root){
        if(root==NULL)
            return 0;
        return (root->val + (sumTree(root->left) + sumTree(root->right))%mod )%mod;
    }

    long long int maxPro(TreeNode* root){
        if(root==NULL)
            return 0;

        long long int l=maxPro(root->left);
        long long int r=maxPro(root->right);

        if(l>0){
            maxi=max(maxi,(((sum-l+mod)%mod)*l)%mod);
        }
        if(r>0){
            maxi=max(maxi,(((sum-r+mod)%mod)*r)%mod);
        }
        return (root->val+(l+r)%mod)%mod;
    }
public:
    int maxProduct(TreeNode* root) {
        sum=sumTree(root);
        maxPro(root);
        return maxi;
    }
};
