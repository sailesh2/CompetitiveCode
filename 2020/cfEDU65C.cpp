#include<bits/stdc++.h>

using namespace std;
int parent[500005];
int has[500005]={0};
int grpCnt[500005]={0};
vector<int> grpMap[500005];

void formParents(int root,int p,vector<int>* grps){

    for(int i=0;i<grpMap[root].size();i++){
        int gr=grpMap[root][i];
        if(has[gr]==0){
            has[gr]=1;
            for(int j=0;j<grps[gr].size();j++){
                int val=grps[gr][j];
                if(parent[val]==-1){
                parent[val]=p;
                grpCnt[parent[val]]++;
                formParents(val,p,grps);
                }

            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        parent[i]=-1;
    }
    int k,x;
    vector<int> grps[m];
    for(int i=0;i<m;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>x;
            grps[i].push_back(x);
            grpMap[x].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(parent[i]==-1)
        formParents(i,i,grps);
    }

    for(int i=1;i<=n;i++){
        if(parent[i]==-1)
        cout<<"1 ";
        else
        cout<<grpCnt[parent[i]]<<" ";
    }
    return 0;
}
