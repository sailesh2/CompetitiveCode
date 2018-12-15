#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int c[200];
int p[200][200];
int dp[200][200]={0};
    int n,m,k;
int paint(int,int);
int main(){

    cin>>n>>m>>k;
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>c[i];
        if(c[i]==0){
            cnt=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            cin>>p[i][j];
        }
    }
    if(cnt==0){
        cout<<cnt;
    }else{

    int v = paint(0,1);
    if(v==1000000000){
        cout<<"-1";
    }else{
        cout<<v;
    }

    }
    return 0;
}

int paint(int ind,int col){
    /*if(c[ind]==0){
        if(ind>0){
            c[ind]=c[ind-1];
            paint(ind+1,col);
        }
        if(ind<n-1){
            c[ind]=c[ind+1];
            if(c[ind]!=c[ind-1])
                paint(ind+1,col+1);
            else
                paint(ind+1,col);
        }

    }*/

    int mini=1000000000,val;
    //cout<<ind<<" "<<col<<"df";
    if(col>k){
        return mini+1;
    }
    if(ind==n ){
        if(col==k)
        return 0;
        else
        return mini+1;
    }
    if(ind>n){
        return 0;
    }

    if(c[ind]==0){
        for(int i=1;i<=m;i++){
            c[ind]=i;
            if(ind>0){
                if(c[ind-1]==c[ind]){
                    if(ind+1<n && dp[ind+1][col]!=0)
                        val=dp[ind+1][col]+p[ind][i];
                    else{
                        val=paint(ind+1,col);
                        if(val!=-1)
                            val=val+p[ind][i];
                    }
                }
                else{
                    if(ind+1<n && dp[ind+1][col+1]!=0)
                        val=dp[ind+1][col+1]+p[ind][i];
                    else {
                        val=paint(ind+1,col+1);
                        if(val!=-1)
                            val=val+p[ind][i];
                    }
                }
            }
            else{
                if(ind +1 <n && dp[ind+1][col]!=0)
                    val=dp[ind+1][col]+p[ind][i];
                else{
                    val=paint(ind+1,col);
                    if(val!=-1)
                        val=val+p[ind][i];
                }
            }
            //cout<<ind<<" "<<i<<" "<<val<<" ";
            if(val!=-1)
                mini=min(mini,val);
        }
        c[ind]=0;
    }
    //cout<<ind<<" "<<mini<<"\n";
    dp[ind][col]=mini;
    return mini;
}
