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
    vector<int> flips;
    int currInd=-1;

    bool makeFlips(TreeNode* root, TreeNode* parent, vector<int>& voyage, int dir){
        if(root==NULL)
            return true;
        currInd++;
        if(root->val != voyage[currInd]){
            if(parent == NULL || dir == 1)
                return false;
            if(parent->right == NULL)
                return false;
            if(parent->right->val != voyage[currInd])
                return false;
            parent->left = parent->right;
            parent->right = root;
            root = parent->left;

            flips.push_back(parent->val);
        }
        return makeFlips(root->left, root, voyage, 0) && makeFlips(root->right, root, voyage, 1);
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if(makeFlips(root, NULL, voyage, 0))
            return flips;
        else{
            vector<int> v;
            v.push_back(-1);
            return v;
        }
    }
};
