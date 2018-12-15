#include<stdio.h>
#include<iostream>

using namespace std;

int n,k[2];
int s[2][8000];
int dp[8000][2];
int has[8000][2];
int fun(int player, int index);
void display(int res);

int main(){
    cin>>n;
    cin>>k[0];
    for(int i=0;i<k[0];i++) {
        cin>>s[0][i];
    }
    cin>>k[1];
    for(int i=0;i<k[1];i++) {
        cin>>s[1][i];
    }
    for(int i=0;i<8000;i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
        has[i][0]=0;
        has[i][1]=0;
    }

    for(int i=1;i<n;i++){
        display(fun(0,i));
        for(int j=1;j<n;j++){
            dp[j][0] = (dp[j][0]==2)?-1:dp[j][0];
            dp[j][1] = (dp[j][1]==2)?-1:dp[j][1];
        }
    }
    cout<<"\n";
    for(int i=1;i<n;i++){
       display(fun(1,i));
       for(int j=1;j<n;j++){
            dp[j][0] = (dp[j][0]==2)?-1:dp[j][0];
            dp[j][1] = (dp[j][1]==2)?-1:dp[j][1];
        }
    }
    return 0;
}

void display(int res){
    switch(res) {
            case 0:
                cout<<"Win ";
                break;
            case 1:
                cout<<"Lose ";
                break;
            case 2:
                cout<<"Loop ";
                break;
        }
}

int fun(int player,int index){

    if(dp[index][player] != -1 && dp[index][player] != 2)
        return dp[index][player];

    int status=-1,loopOnce=0,j;

    if(dp[index][player]==2){
        for(int i=0;i<k[player];i++){
            j=(index+s[player][i])%n;
            if(has[j][1-player] == 1){
                return 2;
            }
        }
    }
    for(int i=0;i<k[player];i++){
        j=(index+s[player][i])%n;
        if(j==0){
            status=0;
            break;
        }

        if(has[j][1-player] == 1){
            status = 2;
            loopOnce=1;
        } else {
            if(dp[j][1-player] == 0){
                status = 1;
            } else if(dp[j][1-player]==1){
                status =0;
                break;
            } else {
                has[index][player]=1;
                status = fun(1-player,j);
                has[index][player]=0;
                if((status != 2)) {
                    status = 1-status;
                } else {
                    loopOnce=1;
                }
                if(status==0)
                    break;
            }
        }
    }

    if(status!=0 && loopOnce==1){
        status =2;
    }
    dp[index][player]=status;
    return dp[index][player];
}
