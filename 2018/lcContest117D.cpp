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

    void minCamera(TreeNode* root, TreeNode* parent, int maxReachability){
        if(root == NULL)
            return;
        treeMapIt = treeMap.find(root);
        int cnt=0;
        if(has.count(treeMapIt->second)==0){
            cnt++;
            if(parent != NULL){
                treeMapIt = treeMap.find(parent);
                if(has.count(treeMapIt->second)==0)
                    cnt++;
            }
            if(root->left != NULL){
                treeMapIt = treeMap.find(root->left);
                if(has.count(treeMapIt->second)==0)
                    cnt++;
            }
            if(root->right != NULL){
                treeMapIt = treeMap.find(root->right);
                if(has.count(treeMapIt->second)==0)
                    cnt++;
            }

            if(cnt>=maxReachability){
                ans++;
                has.insert(root);
                if(parent!=NULL)
                has.insert(parent);
                if(root->left!=NULL)
                has.insert(root->left);
                if(root->right!=NULL)
                has.insert(right);
            }
        }

        minCamera(root->left,maxReachability);
        minCamera(root->right,maxReachability);
    }

public:
    int minCameraCover(TreeNode* root) {
        minCamera(root, 3);
        minCamera(root, 2);
        minCamera(root, 1);
        if(ans==0 && root!=NULL)
            ans=1;
        return ans;
    }
};
