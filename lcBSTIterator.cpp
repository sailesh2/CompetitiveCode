#include<bits/stdc++.h>

using namespace std;

// Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BSTIterator {
private:
    vector<int> inOrder;
    int currIndex;
    void fillInorder(TreeNode* root){
        if(root==NULL)
            return;
        fillInorder(root->left);
        inOrder.push_back(root->val);
        fillInorder(root->right);
    }
public:
    BSTIterator(TreeNode *root) {
        fillInorder(root);
        currIndex=0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return currIndex < inOrder.size();
    }

    /** @return the next smallest number */
    int next() {
        return inOrder[currIndex++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
