#include<bits/stdc++.h>

using namespace std;

int n,m;

string arr[2001];
int scraps[2001][2001];

int getValue(int r, int c, int v){
    if(r<0 || c<0 || r>=n || c>=m)
        return 1;

    if(arr[r][c]==v)
        return scraps[r][c]+1;

    return 1;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){


            scraps[i][j]=getValue(i-1,j,arr[i][j]);
            scraps[i][j]=min(scraps[i][j],getValue(i,j-1,arr[i][j]));

        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            scraps[i][j]=min(scraps[i][j],getValue(i+1,j,arr[i][j]));
            scraps[i][j]=min(scraps[i][j],getValue(i,j+1,arr[i][j]));

            ans=ans+scraps[i][j];
        }
    }
    cout<<ans;
    return 0;
}
