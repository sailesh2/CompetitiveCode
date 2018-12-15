#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeClone {
      int val;
      TreeNodeClone *left;
      TreeNodeClone *right;
      TreeNodeClone *parent;
};

class Solution {
private:

    int has[100005]={0};
    int save;
    int mini=100000000;
    struct TreeNodeClone* cloneTree(struct TreeNode* root,struct TreeNodeClone* parent){
        if(root==NULL){
            return NULL;
        }
        struct TreeNodeClone* cloneRoot=(struct TreeNodeClone*)malloc(sizeof(struct TreeNodeClone));
        cloneRoot->val = root->val;

        cloneRoot->parent = parent;

        cloneRoot->left = cloneTree(root->left,cloneRoot);

        cloneRoot->right = cloneTree(root->right,cloneRoot);

        return cloneRoot;
     }

     struct TreeNodeClone* findTarget(struct TreeNodeClone* root, int k){
        if(root==NULL){
            return NULL;
        }
        if(root->val==k){
            return root;
        }
        struct TreeNodeClone* l=findTarget(root->left,k);
        if(l!=NULL)
            return l;
        struct TreeNodeClone* r=findTarget(root->right,k);
        if(r!=NULL)
            return r;

        return NULL;
     };

     void findCloseLeafVal(struct TreeNodeClone* root,int ctr){
        if(root==NULL)
            return;
        if(has[root->val]==1)
            return;

        has[root->val]=1;

        if(root->left==NULL && root->right==NULL){
            if(ctr+1<=mini){
                mini=ctr+1;
                save=root->val;
            }
            return;
        }


        findCloseLeafVal(root->left,ctr+1);
        findCloseLeafVal(root->right,ctr+1);
        findCloseLeafVal(root->parent,ctr+1);


     }
public:
    int findClosestLeaf(TreeNode* root, int k) {
        struct TreeNodeClone* cloneRoot = cloneTree(root,NULL);
        struct TreeNodeClone* targetNode = findTarget(cloneRoot,k);
        findCloseLeafVal(targetNode,0);
        return save;
    }
};
