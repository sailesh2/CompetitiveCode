class Solution {
private:
    vector<pair<int,int>> secondIslands;


    int minDistance(vector<vector<int>>& A, pair<int,int> oneIsland, pair<int,int> secondIsland){
        int d=0;
        if(oneIsland.first<=secondIsland.first){
            if(oneIsland.second<=secondIsland.second){
                for(int i=oneIsland.first;i<=secondIsland.first;i++){
                    for(int j=oneIsland.second;j<=secondIsland.second;j++){
                        if(A[i][j]==0)
                            d++;
                    }
                }
            }else{
                for(int i=oneIsland.first;i<=secondIsland.first;i++){
                    for(int j=secondIsland.second;j<=oneIsland.second;j++){
                        if(A[i][j]==0)
                            d++;
                    }
                }
            }
        }

        d=0;
        if(oneIsland.first<=secondIsland.first){
            if(oneIsland.second<=secondIsland.second){
                for(int i=oneIsland.first;i<=secondIsland.first;i++){
                    for(int j=oneIsland.second;j<=secondIsland.second;j++){
                        if(A[i][j]==0)
                            d++;
                    }
                }
            }
        }
        for(int i=max(oneIsland.first,secondIsland.first);i>=min(oneIsland.first,secondIsland.first);i--){
            if(A[i][min(oneIsland.second,secondIsland.second)]==0){
                d++;
            }
        }

        for(int i=min(oneIsland.second,secondIsland.second);i<=max(oneIsland.second,secondIsland.second);i++){
            if(A[min(oneIsland.first,secondIsland.first)][i]==0){
                d++;
            }
        }
        if(A[min(oneIsland.first,secondIsland.first)][min(oneIsland.second,secondIsland.second)]==0)
            d--;

        int d2=0;
        for(int i=max(oneIsland.first,secondIsland.first);i>=min(oneIsland.first,secondIsland.first);i--){
            if(A[i][max(oneIsland.second,secondIsland.second)]==0){
                d2++;
            }
        }

        for(int i=min(oneIsland.second,secondIsland.second);i<=max(oneIsland.second,secondIsland.second);i++){
            if(A[max(oneIsland.first,secondIsland.first)][i]==0){
                d2++;
            }
        }
        if(A[max(oneIsland.first,secondIsland.first)][max(oneIsland.second,secondIsland.second)]==0)
            d2--;

        return min(d,d2);
    }

    int minDistance(vector<vector<int>>& A, pair<int,int> oneIsland){
        int mini=1000000000;
        for(int i=0;i<secondIslands.size();i++){
            mini=min(mini,minDistance(A, oneIsland,secondIslands[i]));
        }
        return mini;
    }

    int shortBridge(vector<vector<int>>& A){
        int mini=1000000000;
         for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1){
                    mini=min(mini, minDistance(A,make_pair(i,j)));
                }
            }
         }
         return mini;
    }

    void markIsland(vector<vector<int>>& A, int starti, int startj){
        if(starti<0 || starti>=A.size())
            return;
        if(startj<0 || startj>=A[starti].size())
            return;
        if(A[starti][startj] != 1)
            return;

        A[starti][startj]=2;
        secondIslands.push_back(make_pair(starti,startj));
        markIsland(A, starti-1, startj);
        markIsland(A, starti+1, startj);
        markIsland(A, starti, startj-1);
        markIsland(A, starti, startj+1);
    }

    void findIslands(vector<vector<int>>& A){
        int starti=-1,startj=-1;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1){
                    starti=i;
                    startj=j;
                    break;
                }
            }
        }

        markIsland(A, starti, startj);
    }
public:
    int shortestBridge(vector<vector<int>>& A) {
        findIslands(A);
        return shortBridge(A);
    }
};
