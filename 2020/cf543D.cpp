#include<bits/stdc++.h>

using namespace std;

int n;

int calDis(int f, int l){
    return (l-f+n)%n;
}

int main(){
    int m;
    cin>>n>>m;
    int start,stop;
    vector<int> stops[n+1];
    for(int i=0;i<m;i++){
        cin>>start>>stop;
        stops[start].push_back(stop);
    }

    int lastDropDis[n+1];
    for(int i=1;i<=n;i++){
        int mini=n+2;
        int cnt=0;
        for(int j=0;j<stops[i].size();j++){
            int stop = stops[i][j];
            mini=min(mini,calDis(i,stop));
            cnt=1;
        }
        if(cnt==1)
            lastDropDis[i]=mini;
        else
            lastDropDis[i]=0;
    }

    for(int i=1;i<=n;i++){

        int maxi=0;
        for(int j=1;j<=n;j++){
            int totStops = stops[j].size();
            if(totStops>0){
                int totDis = calDis(i,j) + (totStops-1)*n + lastDropDis[j];
                maxi=max(maxi,totDis);
            }
        }

        cout<<maxi<<" ";
    }

    return 0;
}
