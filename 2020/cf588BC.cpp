#include<bits/stdc++.h>

using namespace std;
int n;

bool allDistinct(int* col, int ind){
    int has[100005]={0};
    int has2[100005]={0};
    vector<int> dist2;
    vector<int> dist;
    for(int i=0;i<=ind;i++){
        if(has[col[i]]==0){
            dist.push_back(col[i]);
        }
        has[col[i]]++;

    }
    if(dist.size()==0)
        return true;

    for(int i=0;i<dist.size();i++){
        if(has2[has[dist[i]]]==0){
            dist2.push_back(has[dist[i]]);
            has2[has[dist[i]]]=1;
        }
    }
    if(dist2.size()!=2)
        return false;

    return abs(dist2[0]-dist2[1])==1;
}

int binSear(int* col){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<n && allDistinct(col,save+ctr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}

int main(){
    cin>>n;
    int col[n];
    for(int i=0;i<n;i++){
        cin>>col[i];
    }

    cout<<binSear(col);
    return 0;
}
