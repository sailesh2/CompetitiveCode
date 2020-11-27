#include<bits/stdc++.h>

using namespace std;
vector<int> graph[200005];

int n,m;

int notifier[200005];
int has[200005]={0};
int mini;

bool isCycle(int root){
    for(int i=0;i<graph[root].size();i++){
        int next=graph[root][i];
        if(has[next]==1)
            return true;

        has[next]=1;
        if(isCycle(next))
            return true;
        has[next]=0;
    }
    return false;
}

void minCal(int root){
    mini=min(mini,root);
    for(int i=0;i<graph[root].size();i++){
        int next=graph[root][i];
        if(has[next]==1)
            return;

        has[next]=1;
        minCal(next);
        has[next]=0;
    }
}


void store(int root){
    if(root==mini)
        notifier[root]=0;
    else
        notifier[root]=1;

    for(int i=0;i<graph[root].size();i++){
        int next=graph[root][i];
        store(next);
    }
}

int main(){
    int x,y;
    cin>>n>>m;
    int notRoot[n+1];
    for(int i=0;i<=n;i++){
        notifier[i]=-1;
        notRoot[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        notRoot[y]=1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(notRoot[i]==0){
            mini=i;
            has[i]=1;
            if(isCycle(i)){
                cnt=1;
                break;
            }
            has[i]=0;
        }
    }




    if(cnt==1){
        cout<<"-1";
    }else{

         for(int i=1;i<=n;i++){
            if(notRoot[i]==0){
                mini=i;
                minCal(i);
                store(i);

            }
        }
        int ctr=0;
        for(int i=1;i<=n;i++){
            if(notifier[i]==0)
            ctr++;
            if(notifier[i]==-1){
                cnt=1;
                break;
            }
        }
        if(cnt==0){
            cout<<ctr<<"\n";
            for(int i=1;i<=n;i++){
                char c = (notifier[i]==0?'A':'E');
                cout<<c;
            }
        }else{
            cout<<"-1";
        }
    }
    return 0;
}
