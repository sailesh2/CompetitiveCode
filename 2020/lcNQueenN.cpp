class Solution {
private:
    int col[10]={0};
    int lDiag[64]={0};
    int rDiag[64]={0};
    int ans=0;
    int boardSize;

    bool canBePlaced(int r, int c){
            return col[c]==0 &&
                lDiag[c+r]==0 &&
                rDiag[boardSize-c+r]==0;

    }

    void nQueens(int r, int n){
        if(n==0){
            ans++;
            return;
        }
        if(r==boardSize){
            return;
        }

        for(int i=0;i<boardSize;i++){
            if(canBePlaced(r,i)){
                col[i]=1;
                lDiag[i+r]=1;
                rDiag[boardSize-i+r]=1;
                nQueens(r+1,n-1);
                col[i]=0;
                lDiag[i+r]=0;
                rDiag[boardSize-i+r]=0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        boardSize=n;
        nQueens(0,n);
        return ans;
    }
};
