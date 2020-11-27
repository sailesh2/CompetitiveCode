class Solution {
private:
    int visited[505][505]={0};
    int possible[505][505]={0};

    void visitBoundary(vector<vector<int>>& A, int i, int j){
        if(visited[i][j]==0)
            return;

        if(i<0 || i>=A.size() || j<0 || j>A[i].size())
            return;

        visited[i][j]=1;
        possible[i][j]=1;
        visitBoundary(A, i+1, j);
        visitBoundary(A, i-1, j);
        visitBoundary(A, i, j+1);
        visitBoundary(A, i, j-1);
    }

    void visitBoundary(vector<vector<int>>& A){
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1 && visited[i][j]==0 && (j==0 || j==A[i].size()-1)){
                    visitBoundary(A, i, j);
                }
            }
        }
    }

    int countPossibles(){
        int cnt=0;
        for(int i=0;i<505;i++){
            for(int j=0;j<505;j++){
                if(possible[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        visitBoundary(A);
        return countPossibles();
    }
};
