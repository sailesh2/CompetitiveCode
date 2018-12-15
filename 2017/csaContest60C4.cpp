#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>k>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int pos[k];
    for(int i=0;i<k;i++){
        pos[i]=-1;
    }
    int ctr=1,zero=0;
    for(int i=0;i<n;i++){
        firstCol[arr[i][0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=arr[i-1][j]){
                if(pos[arr[i-1][j]]==-1){
                    if(j>0 && zero==0 && has[j]==0 && firstCol[arr[i-1][j]]==0){

                        pos[arr[i-1][j]]=0;
                        zero=1;

                    }else{
                        pos[arr[i-1][j]]=ctr;
                        ctr++;
                    }
                }

                if(pos[arr[i][j]]==-1){

                        pos[arr[i][j]]=ctr;
                        ctr++;

                }
                has[j]=1;
                break;
            }
        }
    }
    return 0;
}
