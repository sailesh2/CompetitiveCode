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
    TreeNode* root;
    int cnt=0,total;
    vector<TreeNode*> trees;
    vector<TreeNode*> nodes;

    void createNodes(){
        for(int i=1;i<=total;i++){
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->val=i;
            node->left=NULL;
            node->right=NULL;
            nodes.push_back(node);
        }
    }

    TreeNode* mimicTree(TreeNode* node){
        if(node==NULL)
            return NULL;
        TreeNode* nodeCopy = (TreeNode*)malloc(sizeof(TreeNode));
        nodeCopy->val=node->val;
        nodeCopy->left=mimicTree(node->left);
        nodeCopy->right=mimicTree(node->right);
        return nodeCopy;
    }

    void copyTreeIntoResult(){
        trees.push_back(mimicTree(root));
    }

    void generateTrees(int parent, int dir, int start, int end, bool last){
        if(parent!=-1){
            if(dir==0)
                nodes[parent]->left=NULL;
            else
                nodes[parent]->right=NULL;
        }

        if(start>end){
            if(last){
                copyTreeIntoResult();
            }
            return;
        }


        for(int i=start;i<=end;i++){
            if(parent==-1){
                root=nodes[i];
            }else{
                if(dir==0)
                    nodes[parent]->left=nodes[i];
                else
                    nodes[parent]->right=nodes[i];
            }
            generateTrees(i,0,start,i-1,false);
            generateTrees(i,1,i+1,end,last);

        }
    }

    void preprocess(int n){
        total=n;
        createNodes();
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        preprocess(n);
        generateTrees(-1,-1,0,n-1,true);
        return trees;
    }
};
