#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        char grid[n][m];
        if(n%2==0 || m%2==0){
            if(n%2==0){
                int cnt=0;
                char c;
                for(int j=0;j<n;j++){
                    if(cnt==0)
                        c='B';
                    else
                        c='W';
                    for(int k=0;k<m;k++){
                        grid[j][k]=c;
                    }
                    cnt=1-cnt;
                }

                grid[1][0]='B';
            }else{
                int cnt=0;
                char c;
                for(int j=0;j<m;j++){
                    if(cnt==0)
                        c='B';
                    else
                        c='W';
                    for(int k=0;k<n;k++){
                        grid[k][j]=c;
                    }
                    cnt=1-cnt;
                }

                grid[0][1]='B';
            }
        }else{
                int cnt=0;
                char c;
                for(int j=0;j<n;j++){

                    for(int k=0;k<m;k++){
                        if(cnt==0)
                            c='B';
                        else
                            c='W';
                        grid[j][k]=c;

                        cnt=1-cnt;
                    }
                }
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++)
                cout<<grid[j][k];
            cout<<"\n";
        }
    }
    return 0;
}
