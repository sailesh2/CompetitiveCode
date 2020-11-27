class Solution {
private:
    int  mp[105][105];
    int INF=1000000000;
    int N;

    map<pair<int,int>,pair<int,int> > chain;
    map<pair<int,int>,pair<int,int> >::iterator chainIt;


    void clearDP(){
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                mp[i][j]=0;
            }
        }
    }


    int chainLength(pair<int,int> p){
        chainIt = chain.find(p);
        if(chainIt==chain.end())
            return 1;
        return chainLength(chainIt->second) + 1;
    }

    int shortPath(vector<vector<int>>& grid){
        vector<pair<int,int> > que;
        que.push_back(make_pair(0,0));
        mp[0][0]=1;
        if(grid[0][0]==1)
            return -1;
        int ctr=1;
        int pl=0;
        int front= 0;
        while(ctr>0){
            pl++;
            pair<int,int> node=que[front];
            ctr--;
            int x=node.first;
            int y=node.second;
            if(x==N-1 && y==N-1){
                return chainLength(make_pair(x,y));
            }

            if(x+1<N && y+1<N && mp[x+1][y+1]==0 && grid[x+1][y+1]==0){
                mp[x+1][y+1]=1;
                que.push_back(make_pair(x+1,y+1));
                chain.insert(make_pair(make_pair(x+1,y+1),make_pair(x,y)));
                ctr++;
            }

            if(y+1<N && mp[x][y+1]==0 && grid[x][y+1]==0){
                mp[x][y+1]=1;
                que.push_back(make_pair(x,y+1));

                chain.insert(make_pair(make_pair(x,y+1),make_pair(x,y)));
                ctr++;
            }

            if(x+1<N && mp[x+1][y]==0 && grid[x+1][y]==0){
                mp[x+1][y]=1;
                que.push_back(make_pair(x+1,y));

                chain.insert(make_pair(make_pair(x+1,y),make_pair(x,y)));
                ctr++;
            }

            if(x+1<N && y-1>=0 && mp[x+1][y-1]==0 && grid[x+1][y-1]==0){
                mp[x+1][y-1]=1;
                que.push_back(make_pair(x+1,y-1));

                chain.insert(make_pair(make_pair(x+1,y-1),make_pair(x,y)));
                ctr++;
            }

            if(x-1>=0 && mp[x-1][y]==0 && grid[x-1][y]==0){
                mp[x-1][y]=1;
                que.push_back(make_pair(x-1,y));

                chain.insert(make_pair(make_pair(x-1,y),make_pair(x,y)));
                ctr++;
            }

            if(y-1>=0 && mp[x][y-1]==0 && grid[x][y-1]==0){
                mp[x][y-1]=1;
                que.push_back(make_pair(x,y-1));

                chain.insert(make_pair(make_pair(x,y-1),make_pair(x,y)));
                ctr++;
            }

            if(x-1>=0 && y-1>=0 && mp[x-1][y-1]==0 && grid[x-1][y-1]==0){
                mp[x-1][y-1]=1;
                que.push_back(make_pair(x-1,y-1));

                chain.insert(make_pair(make_pair(x-1,y-1),make_pair(x,y)));
                ctr++;
            }

            if(x-1>=0 && y+1<N && mp[x-1][y+1]==0 && grid[x-1][y+1]==0){
                mp[x-1][y+1]=1;
                que.push_back(make_pair(x-1,y+1));

                chain.insert(make_pair(make_pair(x-1,y+1),make_pair(x,y)));
                ctr++;
            }
            front++;
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        N=grid.size();
        clearDP();
        return shortPath(grid);
    }
};
