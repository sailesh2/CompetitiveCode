#include<bits/stdc++.h>

using namespace std;
int n,m;

bool isRowInc(vector<vector<int> > arr){
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][j]<=arr[i][j-1])
                return false;
        }
    }
    return true;
}

bool isColInc(vector<vector<int> > arr){
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(arr[j][i]<=arr[j-1][i])
                return false;
        }
    }
    return true;
}

int main(){
    int x;
    cin>>n>>m;
    vector<vector<int> > arr;
    vector<vector<int> > brr;
    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            cin>>x;
            v.push_back(x);
        }
        arr.push_back(v);
    }

    for(int i=0;i<n;i++){
        vector<int> v;
        for(int j=0;j<m;j++){
            cin>>x;
            v.push_back(x);
        }
        brr.push_back(v);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int maxi=max(arr[i][j],brr[i][j]);
            int mini=min(arr[i][j],brr[i][j]);
            arr[i][j]=maxi;
            brr[i][j]=mini;
        }
    }

    if(isRowInc(arr) && isColInc(arr) && isRowInc(brr) && isColInc(brr))
        cout<<"Possible";
    else
        cout<<"Impossible";
    return 0;
}
