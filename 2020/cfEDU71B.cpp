#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];

    int brr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            brr[i][j]=0;
        }
    }

    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                if(i+1<n && j+1<m && arr[i][j+1]==1 && arr[i+1][j]==1 && arr[i+1][j+1]==1){
                    brr[i][j]=1;
                    brr[i+1][j]=1;
                    brr[i][j+1]=1;
                    brr[i+1][j+1]=1;
                    v.push_back(make_pair(i+1,j+1));
                }
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]!=brr[i][j]){
                cnt=1;
                break;
            }
        }
        if(cnt==1)
            break;
    }

    if(cnt==0){
        cout<<v.size()<<"\n";
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<"\n";
        }
    }else{
        cout<<"-1";
    }

    return 0;
}
