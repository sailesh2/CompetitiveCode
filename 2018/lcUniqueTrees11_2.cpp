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

    TreeNode* createNode(int val, TreeNode* left, TreeNode* right){
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val=val;
        node->left=left;
        node->right=right;
        return node;
    }

    void createTrees(vector<TreeNode*> &rootTrees, int index, vector<TreeNode*> leftTrees, vector<TreeNode*> rightTrees){
        if(leftTrees.size()==0)
            leftTrees.push_back(NULL);

        if(rightTrees.size()==0)
            rightTrees.push_back(NULL);

        for(int i=0;i<leftTrees.size();i++){
            for(int j=0;j<rightTrees.size();j++){
                rootTrees.push_back(createNode(index+1, leftTrees[i], rightTrees[j]));
            }
        }
    }

    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> trees;

        for(int i=start;i<=end;i++){
            createTrees(trees,i,generateTrees(start,i-1),generateTrees(i+1,end));
        }

        return trees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(0,n-1);
    }
};
