#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int> >& mines) {
        int has[N][N];
        int maxi=0;
        int maze[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                maze[i][j]=1;
                has[i][j]=10000;
            }
        }

        for(int i=0;i<mines.size();i++){
            maze[mines[i][0]][mines[i][1]]=0;
        }
        int ctr;

        for(int i=0;i<N;i++){
            ctr=0;
            for(int j=0;j<N;j++){
                has[i][j]=min(has[i][j],ctr);
                if(maze[i][j]==0){
                    ctr=0;
                }else{
                    ctr++;
                }
            }
        }

        for(int i=0;i<N;i++){
            ctr=0;
            for(int j=N-1;j>=0;j--){
                has[i][j]=min(has[i][j],ctr);
                if(maze[i][j]==0){
                    ctr=0;
                }else{
                    ctr++;
                }
            }
        }

        for(int i=0;i<N;i++){
            ctr=0;
            for(int j=0;j<N;j++){
                has[j][i]=min(has[j][i],ctr);
                if(maze[j][i]==0){
                    ctr=0;
                }else{
                    ctr++;
                }
            }
        }

        for(int i=0;i<N;i++){
            ctr=0;
            for(int j=N-1;j>=0;j--){
                has[j][i]=min(has[j][i],ctr);
                if(maze[j][i]==0){
                    ctr=0;
                }else{
                    ctr++;
                }
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(maze[i][j]==1){
                    maxi=max(maxi,1+has[i][j]);
                }
            }
        }
        return maxi;
    }
};
