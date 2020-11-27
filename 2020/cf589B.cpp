#include<bits/stdc++.h>

using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    int r[h];
    int c[w];
    int mat[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            mat[i][j]=0;
        }
    }
    for(int i=0;i<h;i++){
        cin>>r[i];
        for(int j=0;j<r[i];j++){
            mat[i][j]=1;
        }
        if(r[i]<w)
            mat[i][r[i]]=-1;
    }
    int cnt=0;
    for(int i=0;i<w;i++){
        cin>>c[i];
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<c[i];j++){
            if(mat[j][i]==-1){
                cnt=1;
                break;
            }
            mat[j][i]=1;
        }
        if(cnt==1)
            break;
        if(c[i]<h){
            if(mat[c[i]][i]==1){
                cnt=1;
                break;
            }
            mat[c[i]][i]=-1;
        }
    }
    if(cnt==1){
        cout<<"0";
    }else{
        long long int ans=1;
        long long int mod=1000000007;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(mat[i][j]==0){
                    ans=(ans*2)%mod;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
