class Solution {
private:
    int n,m;
    map<pair<int,int>, vector<pair<int,int> > graph;

    void storeInd(vector<vector<char>>& grid, int x, int y){
        if(x+1<n && x-1>=0 && grid[x+1][y]!='#' && grid[x-1][y]!='#'){
            graphIt=graph.find(make_pair(x,y));
            vector<pair<int,int> > v;
            if(grapthIt!=graph.end()){
                v=graphIt->second;
                graph.erase(graphIt);
            }
            v.push_back(make_pair(x+1,y));
            v.push_back(make_pair(x-1,y));
            graph.insert(make_pair(make_pair(x,y),v));
        }

        if(y+1<n && y-1>=0 && grid[x][y+1]!='#' && grid[x][y-1]!='#'){
            graphIt=graph.find(make_pair(x,y));
            vector<pair<int,int> > v;
            if(grapthIt!=graph.end()){
                v=graphIt->second;
                graph.erase(graphIt);
            }
            v.push_back(make_pair(x,y+1));
            v.push_back(make_pair(x,y-1));
            graph.insert(make_pair(make_pair(x,y),v));
        }
    }

    void storeGraph(vector<vector<char>>& grid){

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='#'){
                    storeInd(graph,i,j);
                }
                if(grid[i][j]=='B'){
                    start=make_pair(x,y);
                }
                if(grid[i][j]=='T'){
                    endi=make_pair(x,y);
                }
            }
        }
    }

    bool isSame(pair<int,int> f, pair<int,int> s){
        return f.first==s.first && f.second==s.second;
    }

    int dfs(){
        vector<pair<int,int> > que;
        que.push_back(start);
        int ctr=0;
        set<pair<int,int> > done;
        int cnt=0;
        while(que.size()>0 && cnt==0){
            for(int l=0;l<que.size();l++){
                start=que[l];
                done.insert(start);
                graphIt=graph.find(start);
                vector<pair<int,int> > v;
                if(graphIt!=graph.end())
                    v=graphIt->second;
                for(int i=0;i<v.size();i++){
                    if(done.count(v[i])==0){
                        done.insert(v[i]);
                        que.push_back(v[i]);
                    }
                    if(isSame(v[i],endi)){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==1)
                    break;
            }
            ctr++;
        }

        return ctr;
    }
public:
    int minPushBox(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        storeGraph(grid);
        return dfs();
    }
};
