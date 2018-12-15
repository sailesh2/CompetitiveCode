#include<bits/stdc++.h>

using namespace std;

class GravityPuzzleEasy{
public:
    vector<string> solve(vector<string> board){
        int n=board.size();
        int cnt;
        if(n==0)
            return board;
        int m=board[0].length();
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(board[j][i]=='.'){
                    cnt=0;
                    for(int k=j-1;k>=0;k--){
                        if(board[k][i]=='#'){
                            board[k][i]='.';
                            cnt=1;
                            break;
                        }
                    }
                    if(cnt==1){
                        board[j][i]='#';
                    }
                }
            }
        }
        return board;
    }
};
