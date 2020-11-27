/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int d;
    int s=0;

    vector<int> mergeLists(vector<int> a, vector<int> b){
        for(int i=0;i<a.size();i++)
            a[i]++;
        for(int i=0;i<b.size();i++)
            a.push_back(b[i]+1);
        sort(a.begin(),a.end());
        return a;
    }

    vector<int> countPairs(TreeNode* root){
        vector<int> v;
        if(root==NULL){
            return v;
        }

        if(root->left==NULL && root->right==NULL){
            v.push_back(1);
            return v;
        }

        vector<int> vl = countPairs(root->left);
        vector<int> vr = countPairs(root->right);

        int i=vl.size()-1;
        int j=0;

        for(int k=i;k>=0;k--){
            while(j<vr.size()){
                if(vr[j]+vl[k]<=d){
                    j++;
                }else{
                    break;
                }
            }
            s=s+j;
        }

        v = mergeLists(vl,vr);
        return v;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        d=distance;
        countPairs(root);
        return s;
    }
};
