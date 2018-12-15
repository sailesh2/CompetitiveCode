#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int dpDown[100][100];
    int dpUp[100][100];
    int savePath[100][100];

    int n,m;
    vector<vector<int> > mat;
    void clearDPDown(){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                dpDown[i][j]=-2;
            }
        }
    }

    void clearDPUp(){
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                dpUp[i][j]=-2;
            }
        }
    }
    int collectCherryDown(int i,int j){
        if(i>=n || j>=m)
            return 0;
        if(mat[i][j]==-1)
            return -1;
        int d;

        if(dpDown[i+1][j]!=-2){
            d=dpDown[i+1][j];
        }else{
            d=collectCherryDown(i+1,j);
        }
        int r;
        if(dpDown[i][j+1]!=-2){
            r=dpDown[i][j+1];
        }else{
            r=collectCherryDown(i,j+1);
        }
        if(d==-1 && r==-1){
            dpDown[i][j]=-1;
            return -1;
        }
        if(d>r){
            savePath[i][j]=1;
        }else{
            savePath[i][j]=2;
        }
        dpDown[i][j]=max(d,r)+mat[i][j];
        return dpDown[i][j];
    }

    int collectCherryUp(int i,int j){
        if(i<0 || j<0)
            return 0;
        if(mat[i][j]==-1)
            return -1;
        int u;
        if(i-1>=0 && dpUp[i-1][j]!=-2){
            u=dpUp[i-1][j];
        }else{
            u=collectCherryUp(i-1,j);
        }
        int l;
        if(j-1>=0 && dpUp[i][j-1]!=-2){
            l=dpUp[i][j-1];
        }else{
            l=collectCherryUp(i,j-1);
        }
        if(u==-1 && l==-1){
            dpUp[i][j]=-1;
            return -1;
        }
        dpUp[i][j]=max(u,l)+mat[i][j];
        return dpUp[i][j];
    }

    void pickUpCherryDown(int i,int j){
        if(i>=n || j>=m)
            return;
        if(mat[i][j]==1)
            mat[i][j]=0;
        if(savePath[i][j]==1){
            pickUpCherryDown(i+1,j);
        }else{
            pickUpCherryDown(i,j+1);
        }
    }
public:
    int cherryPickup(vector<vector<int> >& grid) {
        mat=grid;
        n=grid.size();
        if(n==0){
            return 0;
        }
        m=grid[0].size();

        clearDPDown();
        int cherries=collectCherryDown(0,0);
        if(cherries ==-1)
            return 0;
        pickUpCherryDown(0,0);
        clearDPUp();
        int cherriesUp=collectCherryUp(n-1,m-1);
        if(cherriesUp==-1)
            return 0;
        return cherries+cherriesUp;
    }
};
