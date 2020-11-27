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
    int ans=0;

    pair<int,int> minDistributeCoins(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }

        pair<int,int> leftCoins = minDistributeCoins(root->left);
        pair<int,int> rightCoins = minDistributeCoins(root->right);

        int coinsAvailable = leftCoins.first + rightCoins.first;
        int coinsNeeded = leftCoins.second + rightCoins.second;

        ans=ans+coinsAvailable+coinsNeeded;

        if(root->val==0){
            coinsNeeded++;
        }else if(root->val>1){
            coinsAvailable+=root->val-1;
        }
        int mini=min(coinsAvailable, coinsNeeded);
        coinsAvailable-=mini;
        coinsNeeded-=mini;
        return make_pair(coinsAvailable,coinsNeeded);
    }

public:
    int distributeCoins(TreeNode* root) {
        minDistributeCoins(root);
        return ans;
    }
};
