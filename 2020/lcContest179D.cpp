class Solution {
private:
    vector<int> tree[101];

    void createTree(vector<vector<int>>& edges){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    double frogProb(int root, int* has, int t, int target){
        double maxiP=0;

        if(t<0)
            return 0;

        if(root==target && t ==0)
            return 1;
        int c=0;
        for(int i=0;i<tree[root].size();i++){
            int child = tree[root][i];
            if(has[child]==0){
                has[child]=1;
                c++;
                double v=frogProb(child,has,t-1,target);
                if(v!=0){
                    maxiP=v;
                }
            }
        }

        if(c==0){
            if(target==root)
                return 1;
            else
                return 0;
        }
        return maxiP*((double)1/c);
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        createTree(edges);
        int has[101]={0};
        has[1]=1;
        return frogProb(1,has,t,target);
    }
};
