#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int u,v;
    int graph[m][2];
    vector<int> edge[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[i][0]=u;
        graph[i][1]=v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int partitionHas[n+1];
    int possible[n+1][4];
    for(int i=0;i<=n;i++){
        partitionHas[i]=0;
        possible[i][0]=0;
        possible[i][1]=0;
        possible[i][2]=0;
        possible[i][3]=0;
    }

    int cnt=0;
    for(int i=0;i<m;i++){
        u=graph[i][0];
        v=graph[i][1];

        if(partitionHas[u]==0 && partitionHas[v]==0){
            partitionHas[u]=1;
            partitionHas[v]=2;
            possible[u][2]=1;
            possible[v][1]=1;
        }else if(partitionHas[u]!=0 && partitionHas[v]==0){
            partitionHas[v]=1+(partitionHas[u]+1)%3;
            possible[v][partitionHas[u]]=1;
        }else if(partitionHas[u]==0 && partitionHas[v]!=0){
            partitionHas[u]=1+(partitionHas[v]+1)%3;
            possible[u][partitionHas[v]]=1;
        }else{
            if(partitionHas[u]==partitionHas[v]){

                if(partitionHas[v]==1){
                    if(possible[u][2]==0){
                        possible[u][1]=1;
                        possible[v][2]=1;
                        partitionHas[u]=2;
                    }else if(possible[u][3]==0){
                        possible[u][1]=1;
                        possible[v][3]=1;
                        partitionHas[u]=3;
                    }else{
                        cnt=1;
                        break;
                    }
                }else if(partitionHas[v]==2){
                    if(possible[u][1]==0){
                        possible[u][2]=1;
                        possible[v][1]=1;
                        partitionHas[u]=1;
                    }else if(possible[u][3]==0){
                        possible[u][2]=1;
                        possible[v][3]=1;
                        partitionHas[u]=3;
                    }else{
                        cnt=1;
                        break;
                    }
                }else{
                    if(possible[u][2]==0){
                        possible[u][3]=1;
                        possible[v][2]=1;
                        partitionHas[u]=2;
                    }else if(possible[u][1]==0){
                        possible[u][3]=1;
                        possible[v][1]=1;
                        partitionHas[u]=1;
                    }else{
                        cnt=1;
                        break;
                    };
                }
            }
        }
    }

    if(cnt==1){
        cout<<"-1";
    }else{
        int one=0,two=0,three=0;
        for(int i=1;i<=n;i++){
            if(partitionHas[i]==0){
                cnt=1;
                break;
            }
            if(partitionHas[i]==1)
                one++;
            if(partitionHas[i]==2)
                two++;
            if(partitionHas[i]==3)
                three++;
        }
        if(cnt==1 || three==0){
            cout<<"-1";
        }else{
            for(int i=1;i<=n;i++){
                if(partitionHas[i]==1){
                    if(edge[i].size() != two+three){
                        cnt=1;
                        break;
                    }
                }
                if(partitionHas[i]==2){
                    if(edge[i].size() != one+three){
                        cnt=1;
                        break;
                    }
                }
                if(partitionHas[i]==3){
                    if(edge[i].size() != two+one){
                        cnt=1;
                        break;
                    }
                }
            }
            if(cnt==1){
                cout<<"-1";
            }else{
                for(int i=1;i<=n;i++){
                    cout<<partitionHas[i]<<" ";
                }
            }
        }
    }
    return 0;
}
