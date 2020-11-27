class Solution {
private:
    int DEFAULT=1000000007;
    int graphRed[105][105];
    int graphBlue[105][105];
    int n;

    void setupGraph(vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges){

        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                graphRed[i][j]=0;
                graphBlue[i][j]=0;
            }
        }

        for(int i=0;i<red_edges.size();i++){
            graphRed[red_edges[i][0]][red_edges[i][1]]=1;
        }

        for(int i=0;i<blue_edges.size();i++){
            graphBlue[blue_edges[i][0]][blue_edges[i][1]]=1;
        }
    }

    int shortAltPath(int dest, int col){
        if(dest==0)
            return 0;
        vector<pair<int,pair<int,int>>> que;
        que.push_back(make_pair(0,make_pair(0,col)));
        int fr=0;
        int src,dis;
        int hasR[105]={0};
        int hasB[105]={0};
        if(col==0)
        hasR[0]=1;
        else
        hasB[0]=1;

        while(fr<que.size()){

            src=que[fr].first;
            dis=que[fr].second.first;
            col=que[fr].second.second;
            for(int i=0;i<n;i++){
                if(col==0){
                    if(graphBlue[src][i]==1 && hasB[i]==0){
                        if(i==dest){
                            return dis+1;
                        }
                        hasB[i]=1;
                        que.push_back(make_pair(i,make_pair(dis+1,1)));
                    }
                }else{

                     if(graphRed[src][i]==1 && hasR[i]==0){
                         if(i==dest){
                            return dis+1;
                        }
                        hasR[i]=1;
                        que.push_back(make_pair(i,make_pair(dis+1,0)));
                     }
                }
            }

            fr++;
        }

        return -1;

    }

    vector<int> shortAltPaths(int n){
        vector<int> altPaths;
        for(int i=0;i<n;i++){
            int colRAns=shortAltPath(i,0);
            int colBAns=shortAltPath(i,1);

            if(colRAns == -1 && colBAns==-1)
                altPaths.push_back(-1);
            else if(colRAns==-1)
                altPaths.push_back(colBAns);
            else if(colBAns==-1)
                altPaths.push_back(colRAns);
            else
                altPaths.push_back(min(colRAns,colBAns));
        }

        return altPaths;
    }
public:
    vector<int> shortestAlternatingPaths(int N, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        n=N;
        setupGraph(red_edges, blue_edges);

        return shortAltPaths(n);
    }
};
