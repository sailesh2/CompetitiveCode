class Solution {
private:
    int n,m,k;
    vector<pair<pair<int,int>,pair<int,int>>> que;
    map<pair<int,int>,int> visited;
    map<pair<int,int>,int>::iterator visitedIt;
    vector<vector<int>> grid;

    void insertInQueue(int x, int y, pair<int,int> pathCost){
        int pathLength = pathCost.first;
        int kTaken = pathCost.second;
        if(x<0 || x>=n || y<0 || y>=m)
            return;

        visitedIt = visited.find(make_pair(x,y));

        if(visitedIt==visited.end()){
            if(grid[x][y]==0)
                que.push_back(make_pair(make_pair(x,y),make_pair(pathLength+1,kTaken)));
            else if(kTaken<k)
                que.push_back(make_pair(make_pair(x,y),make_pair(pathLength+1,kTaken+1)));
        }else{
            int kPrev= visitedIt->second;
            if(grid[x][y]==0 && kTaken<kPrev)
                que.push_back(make_pair(make_pair(x,y),make_pair(pathLength+1,kTaken)));
            else if(kTaken+1<kPrev)
                que.push_back(make_pair(make_pair(x,y),make_pair(pathLength+1,kTaken+1)));
        }
    }
public:
    int shortestPath(vector<vector<int>>& mat, int k1) {
        k=k1;
        grid=mat;
        n=grid.size();
        m = grid[0].size();
        que.push_back(make_pair(make_pair(0,0),make_pair(0,0)));
        int f=0,r=0;

        while(f<=r){

            for(int i=f;i<=r;i++){
                pair<int,int> root = que[i].first;
                pair<int,int> pathCost = que[i].second;
                int x = root.first;
                int y = root.second;
                if(x==n-1 && y==m-1)
                    return pathCost.first;
                bool goahead=true;
                visitedIt=visited.find(root);
                if(visitedIt!=visited.end()){
                    int kPrev=visitedIt->second;
                    if(pathCost.second>=kPrev)
                        goahead=false;
                    else
                        visited.erase(visitedIt);
                }
                if(goahead){
                    insertInQueue(x-1,y,pathCost);
                    insertInQueue(x+1,y,pathCost);
                    insertInQueue(x,y-1,pathCost);
                    insertInQueue(x,y+1,pathCost);

                    visited.insert(make_pair(root,pathCost.second));
                }
            }
            f=r+1;
            r=que.size()-1;
        }
        return -1;
    }
};
