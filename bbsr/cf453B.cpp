#include<bits/stdc++.h>

using namespace std;
int n;

vector<int> tree[100005];
int color[100005];
int has[100005]={0};
int ctr=0;

void colorTree(int root,int curr){
    int next;
    if(color[root]!=curr)
        ctr++;
    for(int i=0;i<tree[root].size();i++){
        next=tree[root][i];
        if(has[next]==0){
            has[next]=1;
            colorTree(next,color[root]);
            has[next]=0;
        }
    }
}
int main(){
    cin>>n;
    int p;
    for(int i=0;i<n-1;i++){
        cin>>p;
        tree[p-1].push_back(i+1);
        tree[i+1].push_back(p-1);
    }
    for(int i=0;i<n;i++){
        cin>>color[i];
    }
    has[0]=1;
    colorTree(0,0);
    has[0]=0;
    cout<<ctr;
    return 0;
}
