class TreeAncestor {
private:
    struct Node{
        int val;
        int p;
        vector<int> binLifts;
        vector<Node*> children;
    };

    vector<Node*> tree;

    void createTree(int n, vector<int>& parent){
        for(int i=0;i<n;i++){
            Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->val = i;
            tree.push_back(node);
        }

        tree[0]->p=-1;

        for(int i=1;i<n;i++){
            tree[i]->p=parent[i];
            tree[parent[i]]->children.push_back(tree[i]);
        }
    }

    void createBinaryLifts(Node* root){

        int parent = root->p;
        int ctr=1;
        while(parent!=-1){
            root->binLifts.push_back(parent);
            parent = tree[parent]->binLifts[ctr-1];
            ctr=ctr*2;
        }

        for(int i=0;i<root->children.size();i++){
            createBinaryLifts(root->children[i]);
        }
    }

    int kthAncestor(Node* root, int k){
        int save=0;
        int save2=0;
        int ctr=1;
        int rootInd=0;

        while(1){
            while(save+ctr<=k && save+ctr<=root->binLifts.size()){
                save2=save+ctr;
                rootInd=root->binLifts[save+ctr-1];
                ctr=ctr*2;
            }

            if(save==save2){
                break;
            }

            save=save2;
            root=tree[rootInd];
            ctr=1;
        }

        return root->val;
    }

public:
    TreeAncestor(int n, vector<int>& parent) {
        createTree(n,parent);
        createBinayLifts(tree[0]);
    }

    int getKthAncestor(int node, int k) {
        return kthAncestor(tree[node],k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
