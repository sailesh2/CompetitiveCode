#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    char board[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){

                if(i+2<n && j+1<n && j-1>=0 && board[i+1][j]=='.' && board[i+1][j-1]=='.' && board[i+2][j]=='.' && board[i+1][j+1]=='.'){
                    board[i+1][j]='#';
                    board[i+1][j-1]='#';
                    board[i+2][j]='#';
                    board[i+1][j+1]='#';
                }else{
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==1)
            break;
    }
    if(cnt==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
