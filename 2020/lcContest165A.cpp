class Solution {
private:
    int grid[3][3];

    bool isWin(int ctr){
        for(int i=0;i<3;i++){
            int cnt=0;
            for(int j=0;j<3;j++){
                if(grid[i][j]!=ctr){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                return true;
        }

        for(int i=0;i<3;i++){
            int cnt=0;
            for(int j=0;j<3;j++){
                if(grid[j][i]!=ctr){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                return true;
        }

        return false;
    }

    bool isWin(){

        return isWin(0) || isWin(1) || (grid[0][0]!=-1 && grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2]) ||
        (grid[0][2]!=-1 && grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0]);

    }

    bool isPending(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==-1)
                    return true;
            }
        }
        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                grid[i][j]=-1;
            }
        }
        int ctr=0;
        int ans=-1;
        for(int i=0;i<moves.size();i++){
            grid[moves[i][0]][moves[i][1]]=ctr;

            if(isWin()){
                ans=ctr;
                break;
            }
            ctr=1-ctr;
        }
        if(ans==0){
            return "A";
        }else if(ans==1){
            return "B";
        }else if(isPending()){
            return "Pending";
        }else{
            return "Draw";
        }
    }
};
