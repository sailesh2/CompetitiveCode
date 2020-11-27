#include<bits/stdc++.h>

using namespace std;
vector<int> graph[100005];
vector<int> path;
int has[100005]={0};
int has2[100005]={0};
int save,cnt=0;

int n,m,k;

bool isCycle(int root, int parent, int l){

    for(int i=0;i<graph[root].size();i++){
        int next = graph[root][i];
        if(next!=parent){
            if(has[next]!=0){
                if(abs(l-has[next])+1<=k){
                       // cout<<"d"<<l<<" "<<has[next];
                    save=next;
                    path.push_back(root);
                    return true;
                }
            }else{
                has[next]=l+1;
                if(isCycle(next,root,l+1)){
                    if(cnt==0)
                        path.push_back(root);
                    if(save==root)
                        cnt=1;
                    return true;
                }
            }
        }
    }

    return false;
}

bool independentSet(int root, int parent, int ctr){
    if(ctr==0)
        path.push_back(root);
    int l = path.size();

        //cout<<"l"<<path.size();
    if(l==(k/2+k%2)){
        return true;
    }
    for(int i=0;i<graph[root].size();i++){

        int next = graph[root][i];
        if(next!=parent){
            if(has2[next]==0){
                has2[next]=1;
                if(independentSet(next, root, 1-ctr))
                return true;
            }
        }
    }

    return false;
}


int main(){
    cin>>n>>m>>k;
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    has[1]=1;

    if(isCycle(1,0,1) && path.size()>0){

        cout<<"2\n";
        cout<<path.size()<<"\n";
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<" ";

    }else{
        has2[1]=1;
        independentSet(1,0,0);
        cout<<"1\n";
        for(int i=0;i<k/2+k%2;i++)
            cout<<path[i]<<" ";
    }
    return 0;
}
