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
vector<int> pre;
vector<int> in;
int root=0;

TreeNode* CreateNode(){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val=pre[root];
    node->left=NULL;
    node->right=NULL;
    return node;
}

TreeNode* constructTree(int leftRange, int rightRange){

    TreeNode* node = NULL;

    for(int i=leftRange;i<=rightRange;i++){
        if(in[i]==pre[root]){
            node = CreateNode();
            root++;
            node->left = constructTree(leftRange, i-1);
            node->right = constructTree(i+1, rightRange);
            break;
        }
    }

    return node;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        pre=preorder;
        in=preorder;
        sort(in.begin(),in.end());
        return constructTree(0,in.size()-1);
    }
};
