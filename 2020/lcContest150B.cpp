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
    long long int maxLevelValue=-1000000;
    int maxLevel=0;

    void calMaxLevel(int level, vector<TreeNode*> levelNodes){
        long long int lValues =0 ;
        vector<TreeNode*> nextLevelNodes;
        for(int i=0;i<levelNodes.size();i++){
            lValues = lValues + levelNodes[i]->val;
            if(levelNodes[i]->left!=NULL)
                nextLevelNodes.push_back(levelNodes[i]->left);
            if(levelNodes[i]->right!=NULL)
                nextLevelNodes.push_back(levelNodes[i]->right);
        }
        if(lValues > maxLevelValue){
            maxLevelValue = lValues;
            maxLevel = level;
        }
        if(nextLevelNodes.size()>0)
            calMaxLevel(level+1,nextLevelNodes);
    }
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<TreeNode*> levelNodes;
        levelNodes.push_back(root);
        calMaxLevel(1,levelNodes);
        return maxLevel;
    }
};
