class Solution {
private:
    vector<int> inorder[100005];
    vector<int> outorder[100005];

    int minReorder(int root, int parent){
        int c=0;
        for(int i=0;i<outorder[root].size();i++){
            int next = outorder[root][i];
            if(next!=parent){
                c=c+1+minReorder(next, root);
            }
        }

        for(int i=0;i<inorder[root].size();i++){
            int next = inorder[root][i];
            if(next!=parent){
                c=c+minReorder(next, root);
            }
        }

        return c;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            outorder[u].push_back(v);
            inorder[v].push_back(u);
        }

        return minReorder(0,-1);
    }
};
