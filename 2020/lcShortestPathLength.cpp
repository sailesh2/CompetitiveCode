class Solution {
private:
    int shortest(int root, vector<vector<int>>& graph, int* has){
        int c=0;
        for(int i=0;i<graph[root].size();i++){
            int next=graph[root][i];

            if(has[next]==0){
                has[next]=1;
                c=c+shortest(next,graph,has);
            }
        }
        return 1+c;
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int mini=1000000007;
        for(int i=0;i<graph.size();i++){
            int has[20]={0};
            has[i]=1;
            mini=min(mini,shortest(i,graph,has));
        }
        return mini;
    }
};
