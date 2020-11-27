#include<bits/stdc++.h>

using namespace std;

string winner(int c, int n, int m){

    int player=0;
    while(c>0){

        c=c-n;
        c=c-m+1;
        n--;
        m--;
        player=1-player;
    }



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

        int row[51]={0};
        int col[51]={0};
        int r=0,c=0,ctr=0;
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int k=0;k<m;k++){
                if(arr[j][k]==1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                row[j]=1;
                r++;
            }
        }

        for(int j=0;j<m;j++){
            int cnt=0;
            for(int k=0;k<n;k++){
                if(arr[k][j]==1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                col[j]=1;
                c++;
            }
        }


        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(row[j]==1 && col[k]==1){
                    ctr++;
                }
            }
        }
        cout<<winner(ctr,r,c)<<"\n";
    }
    return 0;
}
