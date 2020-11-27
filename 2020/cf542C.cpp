#include<bits/stdc++.h>

using namespace std;
int path[100][100];
int n;
int has[100][100]={0};
int r1,c1,r2,c2,startX,startY,endX,endY;
int mini=1000000000;
void clearDP(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            has[i][j]=0;
    }
}

int cal(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int buildMinPath(int x,int y,string* graph){


    if(x<0 || x>=n || y<0 || y>=n)
        return 0;

    if(x==r2 && y==c2){
        path[x][y]=1;
        return 1;
    }
    if(graph[x][y]=='1'){
        path[x][y]=0;
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

    path[x][y]=v;
    return v;
}

void minCost(int x, int y, int prevx,int prevy, int cnt, string* graph){

    if(x<0 || x>=n || y<0 || y>=n)
        return;

    if(x==r2 && y==c2){
        if(cnt==0)
        mini=0;
        else
        {
            endX=x;
            endY=y;
            cnt=2;
            mini=min(mini,cal(startX,startY,endX,endY));

        }
        return;
    }
    if(graph[x][y]=='1'){
        if(cnt==0){
            cnt=1;
            startX=prevx;
            startY=prevy;
        }else if(cnt==1){

        }else{
            return;
        }
    }else{
        if(cnt==1 || cnt==2){
            endX=x;
            endY=y;
            cnt=2;
            if(path[x][y]==1){
                mini=min(mini,cal(startX,startY,endX,endY));
                return;
            }
        }
    }

    int v=0;
    if(x+1<n){
        if(has[x+1][y]==0){
            has[x+1][y]=1;
            minCost(x+1,y,x,y,cnt,graph);
        }else{
            if(path[x+1][y]==1){
                mini=0;
                return;
            }
        }
    }
    if(x-1>=0){
        if(has[x-1][y]==0){
            has[x-1][y]=1;
            minCost(x-1,y,x,y,cnt,graph);
        }else{
            if(path[x-1][y]==1){
                mini=0;
                return;
            }
        }
    }

    if(y+1<n){
        if(has[x][y+1]==0){
            has[x][y+1]=1;
            minCost(x,y+1,x,y,cnt,graph);
        }else{
            if(path[x][y+1]==1){
                mini=0;
                return;
            }
        }
    }

    if(y-1>=0){
        if(has[x][y-1]==0){
            has[x][y-1]=1;
            minCost(x,y-1,x,y,cnt,graph);
        }else{
            if(path[x][y-1]==1){
                mini=0;
                return;
            }
        }
    }
}

void display(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    cin>>n;

    cin>>r1>>c1;
    cin>>r2>>c2;
    string graph[n];
    for(int i=0;i<n;i++)
        cin>>graph[i];

    has[r1][c1]=1;
    buildMinPath(r1,c1,graph);


    clearDP();
    has[r1][c1]=1;
    minCost(r1,c1,-1,-1,0,graph);
    cout<<mini;
    return 0;
}
