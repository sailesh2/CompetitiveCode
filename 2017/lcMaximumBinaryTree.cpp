#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.*/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxi=-1000000000,save=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                save=i;
            }
        }

        if(save==-1){
            return NULL;
        }
        vector<int> rightV,leftV;
        for(int i=0;i<save;i++){
            leftV.push_back(nums[i]);
        }
        for(int i=save+1;i<nums.size();i++){
            rightV.push_back(nums[i]);
        }
        struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val=maxi;
        node->right=constructMaximumBinaryTree(rightV);
        node->left=constructMaximumBinaryTree(leftV);
        return node;
    }
};


int main(){
    Solution solution;
    vector<int> v;
    solution.constructMaximumBinaryTree(v);
    return 0;
}
