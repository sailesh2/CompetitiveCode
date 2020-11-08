#include<bits/stdc++.h>

using namespace std;

int dp[10][10][10][10];
int mini;
int MAX=1000000000;

void calSteps(int a, int b, int c, int steps, int sum, int* has){
    if(sum==c){
        mini=min(mini,steps);
        return;
    }
    if(has[(sum+a)%10]==0){
        has[(sum+a)%10]=1;
        calSteps(a,b,c,steps+1,(sum+a)%10,has);
        has[(sum+a)%10]=0;
    }

    if(has[(sum+b)%10]==0){
        has[(sum+b)%10]=1;
        calSteps(a,b,c,steps+1,(sum+b)%10,has);
        has[(sum+b)%10]=0;
    }
}

void setup(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int l=0;l<10;l++){
                for(int k=0;k<10;k++){
                    if(dp[i][j][l][k]==-1){
                        mini=MAX;
                        int has[10]={0};
                        if(l!=k){
                            has[l]=1;
                            calSteps(i,j,k,0,l,has);
                            has[l]=0;
                        }else{
                            if(i==0 || j==0)
                                mini=0;
                            else{
                                has[(i+l)%10]=1;
                                calSteps(i,j,k,1,(i+l)%10,has);
                                has[(i+l)%10]=0;

                                int m1=mini;
                                mini=MAX;
                                has[(j+l)%10]=1;
                                calSteps(i,j,k,1,(j+l)%10,has);
                                has[(j+l)%10]=0;
                                mini=min(mini,m1);
                            }
                        }
                        if(mini==MAX)
                            mini=-1;
                        dp[i][j][l][k]=mini;
                        dp[j][i][l][k]=mini;
                    }
                }
            }
        }
    }
}

int main(){
    string s;
    cin>>s;

    setup();
    int ans[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int sum=0,cnt=0;
            int l=0;
            for(int k=1;k<s.length();k++){
                if(dp[i][j][l][(int)s[k]-48]==-1){
                    cnt=1;
                    break;
                }
                sum=sum+max(0,-1+dp[i][j][l][(int)s[k]-48]);
                l=(int)s[k]-48;
            }
            if(cnt==0)
            ans[i][j]=sum;
            else
            ans[i][j]=-1;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
