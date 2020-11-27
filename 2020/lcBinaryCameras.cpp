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
    map<TreeNode*,int> treeMap;
    map<TreeNode*,int>::iterator treeMapIt;

    set<int> has;
    int ctr=0;

    void storeNum(TreeNode* root){
       if(root==NULL)
            return;
       treeMap.insert(make_pair(root,ctr++));
       storeNum(root->left);
       storeNum(root->right);
    }

    int minCamera(TreeNode* root, TreeNode* parent){
        if(root == NULL)
            return 0;


        int lv = minCamera(root->left, root);
        int rv = minCamera(root->right, root);
        if(lv == 1  || rv == 1) {

            ans++;

            treeMapIt = treeMap.find(root);
            has.insert(treeMapIt->second);
            if(parent!=NULL){
                treeMapIt = treeMap.find(parent);
                has.insert(treeMapIt->second);
            }
            if(root->left!=NULL){
                treeMapIt = treeMap.find(root->left);
                has.insert(treeMapIt->second);
            }
            if(root->right!=NULL){
                treeMapIt = treeMap.find(root->right);
                has.insert(treeMapIt->second);
            }

            return 0;

        }else{
            treeMapIt = treeMap.find(root);
            return has.count(treeMapIt->second)==0 ? 1 : 0;
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        storeNum(root);
        if(minCamera(root, NULL)==1){
           ans++;
        }
        return ans;
    }
};
