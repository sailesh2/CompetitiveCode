class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int cnt=0,ctr=0,rx,ry;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='R'){
                    rx=i;
                    ry=j;
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
                break;
        }

        for(int i=rx;i>=0;i--){
            if(board[i][ry]=='p'){
                ctr++;
                break;
            }else if(board[i][ry]=='B'){
                break;
            }
        }

        for(int i=rx;i<board.size();i++){
            if(board[i][ry]=='p'){
                ctr++;
                break;
            }else if(board[i][ry]=='B'){
                break;
            }
        }

        for(int i=ry;i>=0;i--){
            if(board[rx][i]=='p'){
                ctr++;
                break;
            }else if(board[rx][i]=='B'){
                break;
            }
        }

        for(int i=ry;i<board.size();i++){
            if(board[rx][i]=='p'){
                ctr++;
                break;
            }else if(board[rx][i]=='B'){
                break;
            }
        }

        return ctr;
    }
};
