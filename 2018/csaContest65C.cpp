#include<bits/stdc++.h>

using namespace std;
vector<int> tree[100005];
vector<pair<int,int> > tree2[100005];
int maxDegreeNode;
int minDegreeNode;
int n;
int has[100005]={0};
vector<int> path;

void findMaxDegreeNode(){
   int maxi=0;
   for(int i=1;i<=n;i++){
        if(tree[i].size()>maxi){
            maxi=tree[i].size();
            maxDegreeNode=i;
        }
   }

}

int height(int root,int start){
    if(tree[root].size()>2)
        return 1;
    if(tree[root].size()==1){
        if(tree[root][0]==start)
            return 1;
        else
            return height(tree[root][0],start)+1;
    }else{
        if(tree[root][0]!=start)
            return height(tree[root][0],start)+1;
        else
            return height(tree[root][1],start)+1;
    }
}
void findStartNode(){
    int h,mini=n+1;
    for(int i=1;i<=n;i++){
        if(tree[i].size()==1){
            h=height(i,i);
            if(h<mini){
                mini=h;
                minDegreeNode=i;
            }
        }
    }
}

int minHeight(int root){
    int next,h,maxih=0;
    for(int i=0;i<tree[root].size();i++){
        next=tree[root][i];
        if(has[next]==0){
            has[next]=1;
            h=minHeight(next);
            maxih=max(maxih,h);
            tree2[root].push_back(make_pair(h,next));
            has[next]=0;
        }
    }
    return maxih+1;
}
bool fun(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}
void traverse(int root){
    int next;
    path.push_back(root);
    vector<pair<int,int> > v=tree2[root];
    sort(v.begin(),v.end(),fun);
    for(int i=0;i<v.size();i++){
        next=v[i].second;
        if(has[next]==0){
            has[next]=1;
            traverse(next);
            has[next]=0;

            path.push_back(root);
        }
    }
}

void display(){

    for(int i=1;i<=n;i++){
        cout<<i<<"root"<<tree2[i].size()<<"\n";
        for(int j=0;j<tree2[i].size();j++){
            cout<<tree2[i][j].second<<" "<<tree2[i][j].first<<"-";
        }
        cout<<"\n";
    }
}
int main(){

    cin>>n;
    int u,v;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    findStartNode();
    has[minDegreeNode]=1;
    minHeight(minDegreeNode);
    has[minDegreeNode]=0;

    has[minDegreeNode]=1;
    traverse(minDegreeNode);
    has[minDegreeNode]=0;
    int has2[100005]={0};
    int ctr=0;
    vector<int> ans;
    for(int i=0;i<path.size();i++){
        if(has2[path[i]]==0){
            has2[path[i]]=1;
            ctr++;

        }
        ans.push_back(path[i]);
        if(ctr==n)
        break;
    }
    cout<<ans.size()-1<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
