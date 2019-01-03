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
    bool isEmpty(vector<TreeNode*>& nodes){
        for(int i=0;i<nodes.size();i++){
            if(nodes[i]!=NULL)
                return false;
        }
        return true;
    }

    bool isCompleteTree(vector<TreeNode*>& levelNodes){
        vector<TreeNode*> nextLevelNodes;
        int ctr=0;
        for(int i=0;i<levelNodes.size();i++){
            if(levelNodes[i]==NULL){
                ctr=1;
            }
            else{
                if(ctr==1)
                    return false;
                nextLevelNodes.push_back(levelNodes[i]->left);
                nextLevelNodes.push_back(levelNodes[i]->right);
            }
        }
        if(ctr==1){
            return isEmpty(nextLevelNodes);
        }
        levelNodes.clear();
        for(int i=0;i<nextLevelNodes.size();i++){
            levelNodes.push_back(nextLevelNodes[i]);
        }
        return isCompleteTree(levelNodes);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> levelNodes;
        levelNodes.push_back(root);
        return isCompleteTree(levelNodes);
    }
};
