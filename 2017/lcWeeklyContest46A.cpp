class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> N;
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[i].size();j++){
                sm=M[i][j];
                if(i-1>=0){
                    sm=sm+M[i-1][j];
                    if(j+1<M[i].size())
                        sm=sm+M[i-1][j+1];
                    if(j-1>=0)
                        sm=sm+M[i-1][j-1];
                }
                if(i+1<M.size()){
                    sm=sm+M[i+1][j];
                    if(j+1<M[i].size())
                        sm=sm+M[i+1][j+1];
                    if(j-1>=0)
                        sm=sm+M[i+1][j-1];
                }
                if(j+1<M[i].size())
                    sm=sm+M[i][j+1];
                if(j-1>=0)
                    sm=sm+M[i][j-1];
                N[i][j]=(int)math.floor((float)sm/8);
            }
        }
        return N;
    }
};
