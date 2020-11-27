class Solution {
private:
    int graph[101][101];
    int nodes;
    int MAX=1000000000;
    void warshal(){
        for(int k=0;k<nodes;k++){
            for(int i=0;i<nodes;i++){
                if(i!=k){
                    for(int j=0;j<nodes;j++){
                        if(j!=i && j!=k){
                            if((graph[i][k]+graph[k][j])<graph[i][j]){
                                graph[i][j]=graph[i][k]+graph[k][j];
                            }
                        }
                    }
                }
            }
        }
    }

    void fillGraph(vector<vector<int>>& edges){

        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++)
                graph[i][j]=MAX;
        }

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]]=edges[i][2];

            graph[edges[i][1]][edges[i][0]]=edges[i][2];
        }
    }

    int findCity(int thres){
        int save=-1;
        int mini=MAX;
        for(int i=0;i<nodes;i++){
            int ctr=0;
            for(int j=0;j<nodes;j++){
                if(i!=j){
                    if(graph[i][j]<=thres){
                        ctr++;
                    }
                }
            }
            if(ctr<=mini){
                mini=ctr;
                save=i;
            }
        }
        return save;
    }

    void display(){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                cout<<i<<" - "<<j<<"="<<graph[i][j]<<"\n";
            }
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        nodes=n;
        fillGraph(edges);
        warshal();
        //display();
        return findCity(distanceThreshold);
    }
};
