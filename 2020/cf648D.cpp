#include<bits/stdc++.h>

using namespace std;
int dp[51][51];

void clearDP(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++)
            dp[i][j]=0;
    }
}

bool bfs(int x, int y, int n, int m, vector<string>& grid, vector<pair<int,int>>& gpos){
    vector<pair<int,int>> que;
    que.push_back(make_pair(x,y));
    int front=0;
    int rear=0;
    set<pair<int,int>> visited;
    visited.insert(que[0]);
    while(front<que.size()){

        for(int i=front;i<=rear;i++){
            x=que[i].first;
            y=que[i].second;

            if(x-1>=0 && visited.count(make_pair(x-1,y))==0 && grid[x-1][y]!='#'){
                if(grid[x-1][y]=='B')
                    return false;
                if(grid[x-1][y]=='G')
                    dp[x-1][y]=1;
                que.push_back(make_pair(x-1,y));
                visited.insert(make_pair(x-1,y));
            }

            if(x+1<n && visited.count(make_pair(x+1,y))==0 && grid[x+1][y]!='#'){
                if(grid[x+1][y]=='B')
                    return false;
                if(grid[x+1][y]=='G')
                    dp[x+1][y]=1;
                que.push_back(make_pair(x+1,y));

                visited.insert(make_pair(x+1,y));
            }

            if(y-1>=0 && visited.count(make_pair(x,y-1))==0 && grid[x][y-1]!='#'){
                if(grid[x][y-1]=='B')
                    return false;
                if(grid[x][y-1]=='G')
                    dp[x][y-1]=1;
                que.push_back(make_pair(x,y-1));

                visited.insert(make_pair(x,y-1));
            }

            if(y+1<m && visited.count(make_pair(x,y+1))==0 && grid[x][y+1]!='#'){
                if(grid[x][y+1]=='B')
                    return false;
                if(grid[x][y+1]=='G')
                    dp[x][y+1]=1;
                que.push_back(make_pair(x,y+1));

                visited.insert(make_pair(x,y+1));
            }
        }

        front = rear+1;
        rear=que.size()-1;
    }

    for(int i=0;i<gpos.size();i++){
        if(dp[gpos[i].first][gpos[i].second]==0)
            return false;
    }

    return true;
}

vector<vector<int>> getHas(int n, int m){
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        vector<int> v1;
        for(int j=0;j<m;j++){
            v1.push_back(0);
        }
        v.push_back(v1);
    }
    return v;
}

bool canMake(int x, int y, vector<string>& grid, int n, int m, vector<vector<int>>& has){


    if(x==n-1 && y==m-1){
        dp[x][y]=1;
        return true;
    }

    if(dp[x][y]==1)
        return true;

    if(grid[x][y]=='#')
        return false;

    if(x-1>=0 && has[x-1][y]==0){
        has[x-1][y]=1;
        if(canMake(x-1,y,grid,n,m,has)){
            dp[x][y]=1;
            return true;
        }
    }

    if(x+1<n && has[x+1][y]==0){
        has[x+1][y]=1;
        if(canMake(x+1,y,grid,n,m,has)){
            dp[x][y]=1;
            return true;
        }
    }

    if(y-1>=0 && has[x][y-1]==0){
        has[x][y-1]=1;
        if(canMake(x,y-1,grid,n,m,has)){
            dp[x][y]=1;
            return true;
        }
    }

    if(y+1<m && has[x][y+1]==0){
        has[x][y+1]=1;
        if(canMake(x,y+1,grid,n,m,has)){
            dp[x][y]=1;
            return true;
        }
    }

    return false;
}

bool isPossible(vector<string> grid, int n, int m){
    vector<pair<int,int>> gpos;
    vector<pair<int,int>> bpos;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='B'){
                if(i-1>=0 && grid[i-1][j]=='.'){
                    grid[i-1][j]='#';
                }

                if(i+1<n && grid[i+1][j]=='.'){
                    grid[i+1][j]='#';
                }

                if(j-1>=0 && grid[i][j-1]=='.'){
                    grid[i][j-1]='#';
                }

                if(j+1<m && grid[i][j+1]=='.'){
                    grid[i][j+1]='#';
                }

                bpos.push_back(make_pair(i,j));
            }

            if(grid[i][j]=='G'){
                gpos.push_back(make_pair(i,j));
            }
        }
    }

    grid[n-1][m-1]='.';
    clearDP();
    return bfs(n-1,m-1,n,m,grid,gpos);
    /*clearDP();
    for(int i=0;i<gpos.size();i++){
        vector<vector<int>> has = getHas(n,m);
        has[gpos[i].first][gpos[i].second]=1;
        if(!canMake(gpos[i].first, gpos[i].second,grid,n,m,has))
            return false;
    }

    for(int i=0;i<bpos.size();i++){
        vector<vector<int>> has = getHas(n,m);
        has[bpos[i].first][bpos[i].second]=1;
        if(canMake(bpos[i].first, bpos[i].second,grid,n,m,has))
            return false;
    }

    return true;*/
}

bool isOnlyGoodOrBad(vector<string> grid, int n, int m){
    int g=0,b=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='G')
                return false;
        }
    }

    return true;
}

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        vector<string> grid;
        string s;
        for(int j=0;j<n;j++){
            cin>>s;
            grid.push_back(s);
        }

        if(isOnlyGoodOrBad(grid,n,m)){
            cout<<"Yes\n";
        }else if(isPossible(grid,n,m)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
