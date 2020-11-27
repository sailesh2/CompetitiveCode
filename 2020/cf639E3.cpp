#include<bits/stdc++.h>

using namespace std;
vector<int> graph[200005];

int n,m;

int notifier[200005];
int has[200005]={0};
int mini;

bool isCycle(int root){
    mini=min(mini,root);
    for(int i=0;i<graph[root].size();i++){
        int next=graph[root][i];
        if(has[next]==1)
            return true;

        has[next]=1;
        notifier[next]=1;
        if(isCycle(next))
            return true;
        has[next]=0;
    }
    return false;
}


void store(int root){
    for(int i=0;i<graph[root].size();i++){
        int next=graph[root][i];
        if(next==mini)
            notifier[next]=0;
        else
            notifier[next]=1;
        store(next);
    }
}

int main(){
    int x,y;
    cin>>n>>m;
    int notRoot[200005]={0};
    for(int i=0;i<=n;i++)
        notifier[i]=-1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        notRoot[y]=1;
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(notRoot[i]==0){
            mini=i;
            notifier[i]=0;
            has[i]=1;
            if(isCycle(i)){
                cnt=1;
                break;
            }
            has[i]=0;
            if(i!=mini){
                notifier[i]=1;
                store(i);
            }
        }
    }


    if(cnt==1){
        cout<<"-1";
    }else{
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
