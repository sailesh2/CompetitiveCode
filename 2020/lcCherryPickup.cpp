class Solution {
private:
    vector<vector<int>> g;
    int n,m;
    int dp[71][71][71];

    void clearDP(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=m;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
    }

    int getCherry(int r, int c1, int c2){
        if(r==n){
            return 0;
        }

        if(c1<0 || c2<0 || c1>=m || c2>=m)
            return 0;

        if(dp[r][c1][c2]==-1)
            return cherryPickup(r,c1,c2);
        else
            return dp[r][c1][c2];
    }

    int cherryPickup(int r, int c1, int c2){
        if(r==n){
            return 0;
        }

        if(c1<0 || c2<0 || c1>=m || c2>=m)
            return 0;

        int v = (c1==c2)? g[r][c1] : g[r][c1] + g[r][c2];
        int a=0;

        a=max(a,getCherry(r+1,c1-1,c2-1));
        a=max(a,getCherry(r+1,c1,c2-1));
        a=max(a,getCherry(r+1,c1+1,c2-1));

        a=max(a,getCherry(r+1,c1-1,c2));
        a=max(a,getCherry(r+1,c1,c2));
        a=max(a,getCherry(r+1,c1+1,c2));

        a=max(a,getCherry(r+1,c1-1,c2+1));
        a=max(a,getCherry(r+1,c1,c2+1));
        a=max(a,getCherry(r+1,c1+1,c2+1));

        dp[r][c1][c2]=a+v;
        return a+v;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        g=grid;
        n=g.size();
        m=g[0].size();

        clearDP();
        return cherryPickup(0,0,m-1);
    }
};
