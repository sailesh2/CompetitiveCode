#include<bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<TreeNode*> que;
        vector<TreeNode*> tempQue;
        que.push_back(root);
        int maxi=0,ctr1,ctr2,cnt2,ctr3,j;
        while(1){
            ctr1=0;
            cnt2=0;
            ctr2=0;
            for(int i=0;i<que.size();i++){
                if(que[i]!=NULL){
                    j=i;
                    ctr3=0;
                    while(ctr3<ctr2){
                        tempQue.push_back(NULL);
                        j--;
                        ctr3++;
                    }
                    tempQue.push_back(que[i]);
                    ctr1=ctr1+1+ctr2;
                    ctr2=0;
                    cnt2=1;
                }else if(cnt2==1){
                    ctr2++;
                }
            }
            maxi=max(maxi,ctr1);
            if(ctr1==0){
                break;
            }else{
                que.clear();
                que=tempQue;
                tempQue.clear();
            }
        }
        return maxi;
    }
};
