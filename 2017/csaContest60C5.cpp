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
    int has[100005]={0};
    int firstCol[100005]={0};
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
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pos[arr[j][i]]==-1){
                    if(i>0 && zero==0){
                        pos[arr[j][i]]=0;
                        zero=1;
                    }else{
                        pos[arr[j][i]]=ctr;
                        ctr++;
                    }
            }
        }
    }


    for(int i=0;i<k;i++){
        if(pos[i]==-1){
            if(zero==0){
                pos[i]=0;
                zero=1;
            }else{
                pos[i]=ctr;
                ctr++;
            }
        }
    }
    int ans[n][m];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=pos[arr[i][j]];
            if(ans[i][j]==-1 || ans[i][j]>=k){
                cnt=1;
                break;
            }
            if(j==0 && ans[i][j]==0){
                cnt=1;
                break;
            }
        }
        if(cnt==1)
            break;
    }

    int cnt2;
    if(cnt==1){
        cout<<"-1";
    }else{
        for(int i=1;i<n;i++){
            cnt2=0;
            for(int j=0;j<m;j++){
                if(ans[i][j]>ans[i-1][j]){
                    cnt2=1;
                    break;
                }else if(ans[i][j]<ans[i-1][j]){
                    break;
                }
            }
            if(cnt2==0){
                cnt=1;
                break;
            }
        }
        if(cnt==1){
            cout<<"-1";
        }else{
            for(int i=0;i<k;i++){
                cout<<pos[i]<<" ";
            }
        }
    }
    return 0;
}
