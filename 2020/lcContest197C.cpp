class Solution {
private:
    int n;
    int dp[100005];
    vector<pair<int,int>> graph[100005];

    void clearDP(){
        for(int i=0;i<=n=1;i++)
            dp[i]=-1;
    }

    void buildGraph(vector<vector<int>>& edges,vector<double>& prob){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(make_pair(v,prob[i]));
            graph[v].push_back(make_pair(u,prob[i]));
        }
    }

    double maxProb(int start, int end, int* has){

        if(start==end){
            return 1;
        }

        double p =0;
        for(int i=0;i<graph[start].size();i++){
            int child = graph[start][i].first;
            int pr = graph[start][i].second;

            if(has[child]==0){
                has[child]=1;
                p=max(p,pr*maxProb(child,end,has));
                has[child]=0;
            }
        }

        return p;
    }
public:
    double maxProbability(int m, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        n=m;
        //clearDP();
        buildGraph(edges,succProb);
        int has[100005]={0};
        has[start]=1;
        return maxProb(start,end,has);
    }
};
