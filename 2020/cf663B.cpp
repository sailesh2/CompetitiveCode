#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        string belt[n];
        int ctr=0;
        for(int j=0;j<n;j++){
            cin>>belt[j];
            if(belt[j][m-1]=='R')
                ctr++;
        }

        for(int j=0;j<m;j++){
            if(belt[n-1][j]=='D')
                ctr++;
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
