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
    vector<int> nodeValues;

    void inorder(TreeNode* root){
        if(root==NULL)
            return;

        inorder(root->left);
        nodeValues.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* createNode(int m){
        int value=nodeValues[m];
        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        root->left=NULL;
        root->right=NULL;
        root->val=value;
        return root;
    }

    TreeNode* createTree(int l, int r){
        if(l>r)
            return NULL;

        int mid=(l+r)/2;

        TreeNode* root = createNode(mid);
        root->left=createTree(l,mid-1);
        root->right=createTree(mid+1,r);

        return root;
    }

    TreeNode* balanceTree(TreeNode* root){
        inorder(root);

        return createTree(0,nodeValues.size()-1);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        return balanceTree(root);
    }
};
