#include<bits/stdc++.h>

using namespace std;

struct node{
    int type;
    int value;
};
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int v;
    set<int>::iterator stIt;
    set<int> child[n];
    vector<int> parent[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i]==1){
                child[i].insert(j);
                parent[j].push_back(i);
            }
        }
    }
    int cnt;
    int ans[n];
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(child[j].size()==1){
                cnt=1;
                stIt=child[j].begin();
                v=*stIt;
                ans[j]=v;
                for(int k=0;k<parent[v].size();k++){
                    child[parent[v][i]].erase(v);
                }
                child[j].erase(stIt);
                break;
            }
        }
        if(cnt==0){
            for(int j=0;j<n;j++){
                if(child[j].size()>1){
                    cnt=1;
                    stIt=child[j].begin();
                    v=*stIt;
                    for(int k=0;k<parent[v].size();k++){
                        child[parent[v][i]].erase(v);
                    }
                    child[j].erase(stIt);
                    break;
                }
            }
            if(cnt==0)
                break;
        }
    }
    if(cnt==0)
        cout<<"-1";
    else{
        int current[n];
        for(int i=0;i<n;i++){
            current[i]=i;
        }

        for(int i=0;i<n;i++){
            v=current[ans[i]];
            if(v!=i){
            cout<<"R"<<" "<<i<<" "<<v;
            current[v]=i;
            current[i]=v;
            }
        }
    }
    return 0;
}
