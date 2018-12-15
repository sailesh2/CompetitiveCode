struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*,int> dp;
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        TreeNode* child1,*child2;
        child1 = root->left;
        child2 = root->right;
        TreeNode* grand1=NULL,*grand2=NULL,*grand3=NULL,*grand4=NULL;
        if(child1!=NULL){
            grand1 = child1->left;
            grand2 = child1->right;
        }
        if(child2!=NULL){
            grand3 = child2->left;
            grand4 = child2->right;
        }
        int c1,c2;
        if(dp.find(child1)!=dp.end()){
            c1=(dp.find(child1))->second;
        }else{
            c1=rob(child1);
        }
        if(dp.find(child2)!=dp.end()){
            c2=(dp.find(child2))->second;
        }else{
            c2=rob(child2);
        }

        int gc1,gc2,gc3,gc4;
        if(dp.find(grand1)!=dp.end()){
            gc1=(dp.find(grand1))->second;
        }else{
            gc1=rob(grand1);
        }
        if(dp.find(grand2)!=dp.end()){
            gc2=(dp.find(grand2))->second;
        }else{
            gc2=rob(grand2);
        }
        if(dp.find(grand3)!=dp.end()){
            gc3=(dp.find(grand3))->second;
        }else{
            gc3=rob(grand3);
        }
        if(dp.find(grand4)!=dp.end()){
            gc4=(dp.find(grand4))->second;
        }else{
            gc4=rob(grand4);
        }

        int v= max(c1+c2,gc1+gc2+gc3+gc4 + root->val);
        dp.insert(make_pair(root,v));
        return v;
    }
};

