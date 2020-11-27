#include<bits/stdc++.h>

using namespace std;

string winner(int r, int c, int n){
    if(r==n)
        c=0;
    int player=0;
    while(r>0 && c>0){

        if((r+c)%2!=0){
            if(r<c)
                r--;
            else
                c--;
        }else{
            r--;
            c--;
        }

        player=1-player;
    }

    int m = max(r,c);
    player = (player+m)%2;


    if(player==0){
        return "Vivek";
    }else{
        return "Ashish";
    }
}

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        int arr[n][m];
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin>>arr[j][k];
            }
        }

        int r=0,c=0;
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int k=0;k<m;k++){
                if(arr[j][k]==1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                r++;
        }

        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(arr[k][j]==1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                c++;
        }
        cout<<winner(r,c,n)<<"\n";
    }
    return 0;
}
