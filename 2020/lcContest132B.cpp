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
    int maxi=0;

    pair<int,int> maxParentChildDiff(TreeNode* root){
        if(root==NULL){
            return make_pair(-1,-1);
        }

        pair<int,int> p1=maxParentChildDiff(root->left);
        pair<int,int> p2=maxParentChildDiff(root->right);

        int v1;
        if(p1.first!=-1){
             v1=p1.first;
             maxi=max(maxi,abs(root->val - p1.first));

            //cout<<maxi<<" "<<root->val<<" 1\n";
        }else{
            v1=root->val;
        }

        int v2;
        if(p1.second!=-1){
             v2=p1.second;
             maxi=max(maxi,abs(root->val - p1.second));

            //cout<<maxi<<" "<<root->val<<" 2\n";
        }else{
            v2=root->val;
        }

        int v3;
        if(p2.first!=-1){
             v3=p2.first;
             maxi=max(maxi,abs(root->val - p2.first));

            //cout<<maxi<<" "<<root->val<<" 3\n";
        }else{
            v3=root->val;
        }

        int v4;
        if(p2.second!=-1){
             v4=p2.second;
             maxi=max(maxi,abs(root->val - p2.second));
            //cout<<maxi<<" "<<root->val<<" 4\n";
        }else{
            v4=root->val;
        }


        int minV=min(min(min(v1,v2),v3),v4);
        int maxV=max(max(max(v1,v2),v3),v4);

        minV=min(minV,root->val);
        maxV=max(maxV,root->val);
        return make_pair(minV,maxV);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxParentChildDiff(root);
        return maxi;
    }
};
