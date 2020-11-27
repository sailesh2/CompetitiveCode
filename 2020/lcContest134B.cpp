class Solution {
private:
    int n,m;
    int has[100][100]={0};
    vector<vector<int>> g;

    vector<vector<int>> grid1;
    int origColor;

    bool isBorder(int r0,int c0){

        if(r0<0 || r0>=n || c0<0 || c0>=m){
            return true;
        }
        return grid1[r0][c0]!=origColor;
    }

    bool areBorders(int r0,int c0){
        return (isBorder(r0+1,c0))
        || (isBorder(r0-1,c0))
        || (isBorder(r0,c0+1))
        || (isBorder(r0,c0-1));
    }

    void colorBorder(int r0, int c0, int color) {
        if(r0<0 || r0>=n || c0<0 || c0>=m){
            return;
        }
        if(has[r0][c0]==1)
            return;
        if(grid1[r0][c0]!=origColor)
            return;

        has[r0][c0]=1;
        if(areBorders(r0,c0)){
            g[r0][c0]=color;
        }
        colorBorder(r0+1,c0,color);
        colorBorder(r0-1,c0,color);
        colorBorder(r0,c0+1,color);
        colorBorder(r0,c0-1,color);
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        g=grid;
        grid1=grid;
        n=g.size();
        if(n==0)
            return g;
        m=g[0].size();
        origColor=g[r0][c0];
        colorBorder(r0,c0,color);
        return g;
    }
};
