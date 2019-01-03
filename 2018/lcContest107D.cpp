class Solution {
private:
    void clearInfected(int* inf, int n){
        for(int i=0;i<n;i++){
            inf[i]=0;
        }
    }

    int countInfected(int* inf, int n){
        int ctr=0;
        for(int i=0;i<n;i++){
            if(inf[i]==1)
                ctr++;
        }
        return ctr;
    }

    void dfs(int root, vector<vector<int>>& graph, int* infected){
        if(infected[root]==1){
            return;
        }

        infected[root]=1;
        for(int i=0;i<graph[root].size();i++){
            if(i!=root && graph[root][i]==1)
                dfs(i,graph,infected);
        }
    }

    int malwareCount(vector<vector<int>>& graph, vector<int>& initial, int spare){
        int n = graph.size();
        int infected[n];
        clearInfected(infected,n);
        for(int i=0;i<initial.size();i++){
            if(i!=spare){
                dfs(initial[i], graph, infected);
            }
        }
        return countInfected(infected,n);
    }

    int minMalware(vector<vector<int>>& graph, vector<int>& initial){
        int mini=500;
        int save=0;
        int store[400][400];
        for(int i=0;i<initial.size();i++){
            int m=initial[i];
            for(int j=0;j<graph[m].size();j++){
                store[m][j]=graph[m][j];
                graph[m][j]=0;
                if(j!=m){
                store[j][m]=graph[j][m];
                graph[j][m]=0;
                }
            }
            int malc=malwareCount(graph,initial,i);
            if(malc<mini){
                mini=malc;
                save=m;
            }else if(malc==mini){
                save=min(save,m);
            }
            for(int j=0;j<graph[m].size();j++){
                graph[m][j]=store[m][j];
                graph[j][m]=store[j][m];
            }
        }
        return save;
    }
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        return minMalware(graph,initial);
    }
};
