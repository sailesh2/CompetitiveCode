/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
private:
    set<int> exists;

    void storeElements(TreeNode* root, int val){
        if(root==NULL)
            return;
        exists.insert(val);
        if(root->left!=NULL){
            storeElements(root->left,2*val+1);
        }
        if(root->right!=NULL){
            storeElements(root->right,2*val+2);
        }
    }
public:
    FindElements(TreeNode* root) {
        storeElements(root,0);
    }

    bool find(int target) {
        return exists.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
