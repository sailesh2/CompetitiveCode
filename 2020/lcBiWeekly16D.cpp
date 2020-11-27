class Solution {
private:
    pair<int,int> dp[105][105];
    int n;
    vector<string> grid;
    int mod = 1000000007;

    void clearDP(){
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++)
                dp[i][j]=make_pair(-1,-1);
        }
    }

    pair<int,int> getMaxScore(int x, int y){
        if(x<0 || x>=n || y<0 || y>=n)
            return make_pair(-2,-1);

        if(grid[x][y]=='X')
            return make_pair(-2,-1);

        if(x==n-1 && y==n-1)
            return make_pair(0,1);

        int gridVal = (x==0 && y==0)?0:(grid[x][y]-'0');
        pair<int,int> s[3];

        s[0]=(dp[x+1][y].first==-1)?getMaxScore(x+1,y):dp[x+1][y];

        s[1]=(dp[x][y+1].first==-1)?getMaxScore(x,y+1):dp[x][y+1];

        s[2]=(dp[x+1][y+1].first==-1)?getMaxScore(x+1,y+1):dp[x+1][y+1];

        sort(s,s+3);
        int paths=0;
        int maxScore = s[2].first;
        if(maxScore<0){
            dp[x][y]=make_pair(-2,-1);
            return make_pair(-2,-1);
        }else{
            for(int i=0;i<3;i++){
                if(s[i].first==maxScore)
                    paths=(paths+s[i].second)%mod;
            }

            dp[x][y]=make_pair(maxScore+gridVal,paths);
            return make_pair(maxScore+gridVal,paths);
        }
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        grid = board;
        clearDP();

        pair<int,int> p = getMaxScore(0,0);
        vector<int> ans;
        ans.push_back(max(0,p.first));
        ans.push_back(max(0,p.second));
        return ans;
    }
};
