#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,h;
    cin>>n>>m>>h;
    int frontView[m];
    for(int i=0;i<m;i++){
        cin>>frontView[i];
    }

    int leftView[n];
    for(int i=0;i<n;i++){
        cin>>leftView[i];
    }

    int topView[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>topView[i][j];
        }
    }

    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mat[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(leftView[j]>=frontView[i] && topView[j][i]==1){
                mat[j][i]=frontView[i];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(frontView[j]>=leftView[i] && topView[i][j]==1){
                mat[i][j]=leftView[i];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0 && topView[i][j]==1){
                mat[i][j]=1;
            }
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
