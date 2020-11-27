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
    vector<int> A;

    void createA(TreeNode* root){
        if(root==NULL)
            return;
        createA(root->left);
        A.push_back(root->val);
        createA(root->right);
    }

    void createB(int val){
        A.push_back(val);
    }

    pair<int,int> getMax(int left,int right){
        int maxi=-1000000000;
        int sav=-1;
        for(int i=left;i<=right;i++){
            if(A[i]>maxi){
                maxi=A[i];
                sav=i;
            }
        }
        return make_pair(maxi,sav);
    }

    TreeNode* constructB(int left, int right){
        if(left>right)
            return NULL;

        pair<int,int> maxV=getMax(left,right);
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val=maxV.first;
        node->left=constructB(left,maxV.second-1);
        node->right=constructB(maxV.second+1,right);
        return node;
    }

public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        createA(root);
        createB(val);
        return constructB(0,A.size()-1);
    }
};
