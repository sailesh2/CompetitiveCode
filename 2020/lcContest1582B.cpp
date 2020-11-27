class Solution {
private:
    int board[8][8]={0};

    void fillQueens(vector<vector<int>>& queens){
        for(int i=0;i<queens.size();i++){
            board[queens[i][0]][queens[i][1]]=1;
        }
    }

    bool canAttackKing(vector<int> queen){
        int x=queen[0];
        int y=queen[1];

        int xt=x,yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){
            xt=xt+1;

            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }

        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){
            xt=xt-1;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }

        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){

            yt=yt+1;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){

            yt=yt-1;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){

            xt++;
            yt++;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){

            xt--;
            yt++;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){
            xt++;
            yt--;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        xt=x;
        yt=y;
        while(xt>=0 && yt>=0 && xt<8 && yt<8){
            xt--;
            yt--;
            if(xt>=0 && yt>=0 && xt<8 && yt<8){
            if(board[xt][yt]==2)
                return true;
            if(board[xt][yt]==1)
                break;
            }else{
                break;
            }
        }

        return false;
    }

public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        fillQueens(queens);
        board[king[0]][king[1]]=2;

        vector<vector<int> > ans;

        for(int i=0;i<queens.size();i++){
            if(canAttackKing(queens[i])){
                ans.push_back(queens[i]);
            }
        }

        return ans;
    }
};
