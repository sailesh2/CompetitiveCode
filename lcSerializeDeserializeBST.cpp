struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
private:
    int convertToInt(string s){
        int v=0;
        for(int i=0;i<s.length();i++){
            v=v*10+(int)s[i]-48;
        }
        return v;
    }

    string convertToStr(int v){
        string rev="";
        while(v>0){
            rev=rev+(char)(v%10+48);
            v=v/10;
        }
        string conv="";
        for(int i=rev.length()-1;i>=0;i--)
            conv=conv+rev[i];
        return conv;
    }

    void preOrderString(TreeNode* root,string& preS){
        if(root==NULL)
            return;
        preS=preS+convertToStr(root->val)+"^";
        preOrderString(root->left,preS);
        preOrderString(root->right,preS);
    }

    TreeNode* constTreeFromPreOrder(int& ind, vector<int>& pre, int maxi,int mini){
        TreeNode * root = NULL;
        if(ind==pre.size())
            return root;
        if(pre[ind]>=mini && pre[ind]<=maxi){
            root=(TreeNode *)malloc(sizeof(TreeNode));
            root->val=pre[ind];
            root->left=NULL;
            root->right=NULL;
            ind++;

            root->left=constTreeFromPreOrder(ind,pre,root->val,mini);
            root->right=constTreeFromPreOrder(ind,pre,maxi,root->val);
        }
        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preS="";
        preOrderString(root,preS);
        return preS;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodeValues;
        string nodeValue;
        for(int i=0;i<data.length();i++){
            if(data[i]=='^'){
                nodeValues.push_back(convertToInt(nodeValue));
                nodeValue="";
            }else{
                nodeValue=nodeValue+data[i];
            }
        }
        int ind=0;
        return constTreeFromPreOrder(ind,nodeValues,1000000000,-100000000);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

