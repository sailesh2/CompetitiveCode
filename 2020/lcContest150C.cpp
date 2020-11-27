class Solution {
private:
    vector<vector<int>> oneDistance;
    int n,m;
    int INF=100000000;
    void createOneDistance(){
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<m;j++){
                v.push_back(INF);
            }
            oneDistance.push_back(v);
         }
    }

    void storeLandsDis(vector<vector<int>>& grid){
        int ctr=INF;
        for(int i=0;i<m;i++){
         ctr=INF;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    ctr=0;
                }else{
                    ctr++;
                }
                oneDistance[j][i]=ctr;
            }
        }
        for(int i=0;i<m;i++){
            ctr=INF;
            for(int j=n-1;j>=0;j--){
                if(grid[j][i]==1){
                    ctr=0;
                }else{
                    ctr++;
                }
                oneDistance[j][i]=min(ctr,oneDistance[j][i]);
            }
        }
    }

    int storeMinLandDis(vector<vector<int>>& grid){
        int maxD=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int mini=INF;
                    for(int k=0;k<m;k++){
                        mini=min(mini,oneDistance[i][k]+abs(k-j));
                    }
                    if(mini!=INF){
                        maxD = max(maxD,mini);
                    }
                }
            }
        }
        return maxD;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        createOneDistance();
        storeLandsDis(grid);
        return storeMinLandDis(grid);

    }
};
