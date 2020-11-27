class Solution {
private:
    vector<int> tree[100005];
    int subtreecount[100005][26];
    string labels;

    void createTree(vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    void subtree(int root, int* has){
        int counts[26]={0};
        for(int i=0;i<tree[root].size();i++){
            int child = tree[root][i];
            if(has[child]==0){
                has[child]=1;
                subtree(child,has);

                for(int j=0;j<26;j++){
                    counts[j]=counts[j]+subtreecount[child][j];
                }
            }
        }
        counts[labels[root]-'a']++;
        for(int j=0;j<26;j++)
            subtreecount[root][j]=counts[j];
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string label) {
        createTree(edges);
        labels=label;
        int has[100005]={0};
        has[0]=1;
        subtree(0,has);
        vector<int> ans;

        for(int i=0;i<n;i++){
            ans.push_back(subtreecount[i][labels[i]-'a']);
        }
        return ans;
    }
};
