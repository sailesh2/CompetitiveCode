#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    int brr[n][m];

    vector<int> row[n];
    vector<int> col[m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>brr[i][j];
            if(arr[i][j]!=brr[i][j]){
                row[i].push_back(j);
                col[j].push_back(i);
            }
        }
    }

    int gone[505][505]={0};
    int colIndex[505]={0};

    int cnt=0,f,s;
    for(int i=0;i<n;i++){
        cout<<i<<" ";
        int ctr=0;
        for(int j=0;j<row[i].size();j++){
            int colI=row[i][j];
            if(gone[i][colI]==0){
                ctr=1-ctr;
                if(ctr==1){
                    f=j;
                }else{
                    s=j;
                    colI=row[i][f];
                    gone[i][colI]=1;
                    gone[i][row[i][s]]=1;
                    int cnt2=0;
                    for(int k=colIndex[colI];k<col[colI].size();k++){
                        if(gone[col[colI][k]][colI]==0){
                            colIndex[colI]=k+1;
                            gone[col[colI][k]][colI]=1;
                            if(gone[col[colI][k]][row[i][s]]==0)
                            cnt2=1;

                            break;
                        }
                    }
                    if(cnt2==0){
                        cnt=1;
                        break;
                    }
                }
            }

        }
        if(cnt==1 || ctr==1){
            cnt=1;
            break;
        }
    }
    if(cnt==1){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    return 0;
}
