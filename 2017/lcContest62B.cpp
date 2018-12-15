#include<bits/stdc++.h>

using namespace std;

#define inf 99999999

class Solution {
private:
    int graph[200][200];
    int dist[200][200];
    int V;

    int findTotalDelay(){
        int i, j, k;

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

    }
public:
    int networkDelayTime(vector<vector<int> >& times, int N, int K) {
        V=N;
        for(int i=0;i<N;i++)
            graph[i][i]=0;
        for(int i=0;i<N;i++){
            for(int j=0;j!=i && j<N;j++){
                graph[i][j]=inf;
            }
        }
        int u,v,t;
        for(int i=0;i<times.size();i++){
            u=times[i][0];
            v=times[i][0];
            t=times[i][0];

            graph[u][v]=t;
        }

        findTotalDelay();
        int maxi=0;
        for(int i=0;i<N;i++){
            if(dist[K][i]!=inf){
                maxi=max(maxi,dist[K][i]);
            }
        }
        return maxi;
    }
};
