#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<string> b;
    bool isComplete(vector<string> board){
            int cnt=1;
            char save;
            for(int i=0;i<3;i++){
                save=board[i][0];
                cnt=0;
                for(int j=1;j<3;j++){
                    if(board[i][j]!=save){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    if(save!=' ')
                        break;
                    else
                        cnt=1;
                }
            }

            int cnt1=1;
            char save1;
            for(int i=0;i<3;i++){
                save1=board[0][i];
                cnt1=0;
                for(int j=1;j<3;j++){
                    if(board[j][i]!=save1){
                        cnt1=1;
                        break;
                    }
                }
                if(cnt1==0){
                    if(save1!=' ')
                        break;
                    else
                        cnt1=1;
                }
            }

            if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
                cnt=0;
            }
            if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '){
                cnt=0;
            }
        return cnt==0 || cnt1==0;
    }
    void display(vector<string> curr){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<curr[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    bool isValid(int pos,vector<string> curr){
        int cnt=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(curr[i][j]!=b[i][j]){
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
                break;
        }
        if(cnt==0)
            return true;
        if(isComplete(curr)){
            return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(curr[i][j]==' '){
                    curr[i][j]=(pos==0?'X':'O');
                    if(isValid(1-pos,curr))
                        return true;
                    curr[i][j]=' ';
                }
            }
        }

        cnt=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(curr[i][j]!=b[i][j]){
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
                break;
        }
        return cnt==0;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        vector<string> curr;
        b=board;
        for(int i=0;i<3;i++){
            curr.push_back("   ");
        }
        return isValid(0,curr);
    }
};


int main(){
    Solution sol;
    vector<string> v;
    v.push_back("XOX");
    v.push_back("O O");
    v.push_back("XOX");
    sol.validTicTacToe(v);
}
