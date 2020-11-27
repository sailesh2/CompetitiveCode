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
    int currentVal;
    int currentDepth;
    int index=0;

    TreeNode* CreateNewNode(){
        TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
        node->val=currentVal;
        node->left=NULL;
        node->right=NULL;
        return node;
    }

    int getNextVal(string s){
        string num="";
        while(index<s.length()){
            if(s[index]=='-')
                break;

            num.push_back(s[index]);
            index++;
        }

        int n=0;
        for(int i=0;i<num.length();i++){
            n=n*10+((int)num[i]-48);
        }
        return n;
    }

    void updateNextValDepth(string s){
        currentDepth=0;
        while(index<s.length()){
            if(s[index]=='-')
                currentDepth++;
            else{
                currentVal=getNextVal(s);
                break;
            }
            index++;
        }
    }

    TreeNode* recoverTree(string s, int d){
        if(d==currentDepth){
            TreeNode* node = CreateNewNode();
            updateNextValDepth(s);
            node->left=recoverTree(s,d+1);
            if(currentDepth==d+1)
            node->right=recoverTree(s,d+1);
            return node;
        }else{
            return NULL;
        }
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        updateNextValDepth(S);
        return recoverTree(S,0);
    }
};
