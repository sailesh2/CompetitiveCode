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

    TreeNode* findParentNode(TreeNode* parent, TreeNode* root, int delVal){
        if(root==NULL)
            return NULL;
        if(root->val==delVal)
            return parent;
        TreeNode* left = findParentNode(root, root->left, delVal);
        if(left!=NULL)
            return left;
        TreeNode* right = findParentNode(root, root->right, delVal);
        if(right!=NULL)
            return right;
        return NULL;
    }

    pair<TreeNode*,int> findParentNodes(vector<TreeNode*> roots, int delVal){
        TreeNode* nullNode = NULL;
        for(int i=0;i<roots.size();i++){
            if(roots[i]!=NULL){
                if(roots[i]->val==delVal)
                    return make_pair(nullNode,i);

                TreeNode* parent = findParentNode(nullNode,roots[i],delVal);
                if(parent!=NULL)
                    return make_pair(parent,i);
            }
        }
        return make_pair(nullNode,-1);
    }

    pair<vector<TreeNode*>,int> deleteChildNode(vector<TreeNode*> roots,pair<TreeNode*,int> toDelete, int delVal){

        TreeNode* parent = toDelete.first;
        int rootIndex = toDelete.second;
        TreeNode* child;
        vector<TreeNode*> newRoots;
        int s;
        if(parent==NULL){
            child=roots[rootIndex];
            s=1;
        }else{
            if(parent->left!=NULL && parent->left->val==delVal){
                child = parent->left;
                parent->left=NULL;
            }else{
                child=parent->right;
                parent->right=NULL;
            }
            s=0;

        }

        if(child->left!=NULL)
        newRoots.push_back(child->left);

        if(child->right!=NULL)
        newRoots.push_back(child->right);

        return make_pair(newRoots,s);
    }

    vector<TreeNode*> deleteRoots(int delIndex, vector<TreeNode*> roots){
        vector<TreeNode*> newRoots;

        for(int i=0;i<roots.size();i++){
            if(i!=delIndex)
                newRoots.push_back(roots[i]);
        }

        return newRoots;
    }

    vector<TreeNode*> addRoots(vector<TreeNode*> addRoots, vector<TreeNode*> roots){
        for(int i=0;i<addRoots.size();i++)
            roots.push_back(addRoots[i]);
        return roots;
    }

    vector<TreeNode*> del(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        roots.push_back(root);

        for(int i=0;i<to_delete.size();i++){
            pair<TreeNode*,int> toDeleteNode = findParentNodes(roots, to_delete[i]);
            pair<vector<TreeNode*>,int> newRoots=deleteChildNode(roots,toDeleteNode, to_delete[i]);
            if(newRoots.second==1)
                roots=deleteRoots(toDeleteNode.second,roots);
            roots=addRoots(newRoots.first,roots);
        }

        return roots;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        return del(root, to_delete);
    }
};
