#include<bits/stdc++.h>

using namespace std;

int n,k;
int dp[2005][2005]={0};
int dpRows[2005][2005]={0};
int dpCols[2005][2005]={0};
int dpZeroRows[2005]={0};
int dpZeroCols[2005]={0};

void preprocessRows(vector<string>& mat){
    int zr=0;
    for(int i=0;i<n;i++){
        int b=0;
        for(int j=0;j<n;j++){
            if(mat[i][j]=='B')
                b++;
            dpRows[i][j]=b;
        }
        if(b==0)
            zr++;
        dpZeroRows[i]=zr;
    }
}

void preprocessCols(vector<string>& mat){
    int zc=0;
    for(int i=0;i<n;i++){
        int b=0;
        for(int j=0;j<n;j++){
            if(mat[j][i]=='B')
                b++;
            dpCols[j][i]=b;
        }
        if(b==0)
            zc++;
        dpZeroCols[i]=zc;
    }
}

int rowSum(int row, int startCol, int endCol){
    if(startCol>=endCol)
        return 0;

    startCol--;
    endCol--;

    if(startCol>=0)
        return dpRows[row][endCol] - dpRows[row][startCol];
    else if(endCol>=0)
        return dpRows[row][endCol];
    else
        return 0;
}

int colSum(int col, int startRow, int endRow){
    if(startRow>=endRow)
        return 0;

    startRow--;
    endRow--;

    if(startRow>=0)
        return dpCols[endRow][col] - dpCols[startRow][col];
    else if(endRow>=0)
        return dpCols[endRow][col];
    else
        return 0;
}

int zeroRowSum(int startRow, int endRow){
    if(startRow>=endRow)
        return 0;
    startRow--;
    endRow--;

    if(startRow>=0)
        return dpZeroRows[endRow] - dpZeroRows[startRow];
    else if(endRow>=0)
        return dpZeroRows[endRow];
    else
        return 0;
}

int zeroColSum(int startCol, int endCol){
    if(startCol>=endCol)
        return 0;
    startCol--;
    endCol--;

    if(startCol>=0)
        return dpZeroCols[endCol] - dpZeroCols[startCol];
    else if(endCol>=0)
        return dpZeroCols[endCol];
    else
        return 0;
}

void runRow(){
    for(int i=0;i<n;i++){
        if(i+k-1<n){
            int sm=0;
            for(int j=0;j<k;j++){
                if(colSum(j,i+k,n) + colSum(j,0,i)==0)
                    sm++;
            }
            dp[i][0]=sm + zeroColSum(k,n);
            for(int j=k;j<n;j++){
                if(colSum(j-k,i+k,n) + colSum(j-k,0,i)==0)
                    sm--;
                if(colSum(j,i+k,n) + colSum(j,0,i)==0)
                    sm++;
                dp[i][j-k+1] = sm + zeroColSum(j+1,n) + zeroColSum(0,j-k+1);
            }
        }else{
            break;
        }
    }
}

void runCol(){
    for(int i=0;i<n;i++){
        if(i+k-1<n){
            int sm=0;
            for(int j=0;j<k;j++){
                if(rowSum(j,i+k,n) + rowSum(j,0,i)==0)
                    sm++;
            }
            dp[0][i]=dp[0][i]+sm+zeroRowSum(k,n);
            for(int j=k;j<n;j++){
                if(rowSum(j-k,i+k,n) + rowSum(j-k,0,i)==0)
                    sm--;
                if(rowSum(j,i+k,n) + rowSum(j,0,i)==0)
                    sm++;
                dp[j-k+1][i]=dp[j-k+1][i]+sm+zeroRowSum(j+1,n) + zeroRowSum(0,j-k+1);
            }
        }else{
            break;
        }
    }
}

int countMax(){
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxi=max(maxi,dp[i][j]);
        }
    }
    return maxi;
}

int main(){
    cin>>n>>k;

    vector<string> mat;
    for(int i=0;i<n;i++){
        string matI;
        cin>>matI;
        mat.push_back(matI);
    }

    preprocessRows(mat);
    preprocessCols(mat);

    runRow();
    runCol();

    cout<<countMax();
    return 0;
}
