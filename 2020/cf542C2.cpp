#include<bits/stdc++.h>

using namespace std;
int path[100][100];
vector<pair<int,int> > pipeCost[51][51];
int n;
int r1,c1,r2,c2,startX,startY,endX,endY;

int has[100][100]={0};
int mini=1000000000;
void clearDP(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            has[i][j]=0;
    }
}

int cal(pair<int,int> w, pair<int,int> l){
    return (w.first-l.first)*(w.first-l.first) + (w.second-l.second)*(w.second-l.second);
}

void buildPipe(string* graph){
    vector<pair<int,int> > water,land;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]=='1'){
                water.push_back(make_pair(i,j));
            }else{
                land.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0;i<water.size();i++){
        pair<int,int> w=water[i];
        for(int j=0;j<land.size();j++){
            pair<int,int> l=land[j];
            if(path[l.first][l.second]==1)
            pipeCost[w.first][w.second].push_back(l);
        }
    }
}

int buildMinPath(int x,int y,string* graph){

    if(x==r2 && y==c2){
        //path[x][y]=1;
        return 1;
    }
    if(graph[x][y]=='1'){
        //path[x][y]=0;
        return 0;
    }
    int v=0;
    if(x+1<n){
        if(has[x+1][y]==0){
            has[x+1][y]=1;
            v=v|buildMinPath(x+1,y,graph);
        }else{
            v=v|path[x+1][y];
        }
    }
    if(x-1>=0){
        if(has[x-1][y]==0){
            has[x-1][y]=1;
            v=v|buildMinPath(x-1,y,graph);
        }else{
            v=v|path[x-1][y];
        }
    }

    if(y+1<n){
        if(has[x][y+1]==0){
            has[x][y+1]=1;
            v=v|buildMinPath(x,y+1,graph);
        }else{
            v=v|path[x][y+1];
        }
    }

    if(y-1>=0){
        if(has[x][y-1]==0){
            has[x][y-1]=1;
            v=v|buildMinPath(x,y-1,graph);
        }else{
            v=v|path[x][y-1];
        }
    }

    //path[x][y]=v;
    return v;
}

void minCost(int x, int y, pair<int,int> prev,string* graph){

    if(graph[x][y]=='1'){
       // cout<<x<<"P"<<y<<"\n";
        for(int i=0;i<pipeCost[x][y].size();i++){
            pair<int,int> p=pipeCost[x][y][i];
            //cout<<p.first<<" "<<p.first<<"\n";
            mini=min(mini,cal(p,prev));

        }
        return;
    }
    if(x+1<n){
        if(has[x+1][y]==0){
            has[x+1][y]=1;
            minCost(x+1,y,make_pair(x,y),graph);
        }
    }
    if(x-1>=0){
        if(has[x-1][y]==0){
            has[x-1][y]=1;
            minCost(x-1,y,make_pair(x,y),graph);
        }
    }

    if(y+1<n){
        if(has[x][y+1]==0){
            has[x][y+1]=1;
            minCost(x,y+1,make_pair(x,y),graph);
        }
    }

    if(y-1>=0){
        if(has[x][y-1]==0){
            has[x][y-1]=1;
            minCost(x,y-1,make_pair(x,y),graph);
        }
    }

}

int main(){
    cin>>n;

    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--;
    c1--;
    r2--;
    c2--;
    string graph[n];
    for(int i=0;i<n;i++)
        cin>>graph[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            clearDP();
            if(graph[i][j]=='1'){
                has[i][j]=1;
                path[i][j]=0;
            }else{
                //if(has[i][j]==0){
                    has[i][j]=1;
                    path[i][j]=buildMinPath(i,j,graph);
                //}
            }
        }
    }

    buildPipe(graph);

    clearDP();
    if(path[r1][c1]==1){
        cout<<"0";
    }else{
        has[r1][c1]=1;
        minCost(r1,c1,make_pair(-1,-1),graph);
        cout<<mini;
    }
    return 0;
}
