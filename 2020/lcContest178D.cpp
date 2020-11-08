class Solution {
private:
    vector<pair<pair<int,int>,int>> graph[101][101];
    int n,m;

    void fillGraph(int i, int j, int v){
        if(v==1){
            if(i+1<n)
            graph[i][j].push_back(make_pair(make_pair(i+1,j),1));
            if(i-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i-1,j),1));
            if(j-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i,j-1),1));
            if(j+1<m)
            graph[i][j].push_back(make_pair(make_pair(i,j+1),0));
        }

        if(v==2){
            if(i+1<n)
            graph[i][j].push_back(make_pair(make_pair(i+1,j),1));
            if(i-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i-1,j),1));
            if(j-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i,j-1),0));
            if(j+1<m)
            graph[i][j].push_back(make_pair(make_pair(i,j+1),1));
        }

        if(v==3){
            if(i+1<n)
            graph[i][j].push_back(make_pair(make_pair(i+1,j),0));
            if(i-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i-1,j),1));
            if(j-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i,j-1),1));
            if(j+1<m)
            graph[i][j].push_back(make_pair(make_pair(i,j+1),1));
        }

        if(v==4){
            if(i+1<n)
            graph[i][j].push_back(make_pair(make_pair(i+1,j),1));
            if(i-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i-1,j),0));
            if(j-1>=0)
            graph[i][j].push_back(make_pair(make_pair(i,j-1),1));
            if(j+1<m)
            graph[i][j].push_back(make_pair(make_pair(i,j+1),1));
        }
    }

    int bfs(){
        set<pair<int,int>> has;
        vector<pair<pair<int,int>,int> > que;
        que.push_back(make_pair(make_pair(0,0),0));
        has.insert(make_pair(0,0));
        int rear=0;
        pair<pair<int,int>,int> p2;
        while(1){
            pair<pair<int,int>,int> p = que[rear];
            rear++;
            int x=p.first.first;
            int y=p.first.second;
            int ctr=p.second;
            for(int i=0;i<graph[x][y].size();i++){
                p2=graph[x][y][i];
                if(p2.first.first==n-1 && p2.first.second==m-1)
                    return ctr;
                if(has.count(p2.first)==0){
                    has.insert(p2.first);
                    que.push_back(make_pair(p2,ctr+p2.second));
                }
            }
        }
        return 0;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                fillGraph(i,j,grid[i][j]);
            }
        }

        return bfs();
    }
};
