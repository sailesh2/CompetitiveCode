#include<bits/stdc++.h>

using namespace std;

int n,m,p;
vector<int> speed;
vector<string> grid;
vector<pair<int,int>> tentTemp;

void spread(int x, int y, int currSpeed, int index, set<pair<int,int>> has){
    if(x<0 || x>=n || y<0 || y>=m)
        return;
    if(has.count(make_pair(x,y))>0)
        return;
    char val = (char)index+1+48;

    if(currSpeed==speed[index]){
        if(grid[x][y]=='.'){
        grid[x][y]=val;
        tentTemp.push_back(make_pair(x,y));
        }
        return;
    }
  //  cout<<"v"<<val<<"\n";
    if(grid[x][y]== val || grid[x][y]=='.'){
        grid[x][y]=val;
        has.insert(make_pair(x,y));
        spread(x+1,y,currSpeed+1,index,has);
        spread(x-1,y,currSpeed+1,index,has);
        spread(x,y+1,currSpeed+1,index,has);
        spread(x,y-1,currSpeed+1,index,has);
        has.erase(has.find(make_pair(x,y)));
    }
}

void spreadTentacles(int index, vector<pair<int,int>>* tentacles){
    int ctr=0;
    int emptyTent[p];
    for(int i=0;i<p;i++){
        emptyTent[i]=0;
    }
    int cnt;
    while(1){
        cnt=0;
        set<pair<int,int>> has;
        for(int i=0;i<tentacles[index].size();i++){
            spread(tentacles[index][i].first,tentacles[index][i].second,0,index,has);
        }
        tentacles[index].clear();
        if(tentTemp.size()==0)
            emptyTent[index]=1;
        for(int i=0;i<p;i++){
            if(emptyTent[i]==0){
                cnt=1;
                break;
            }
        }
        if(cnt==0)
            break;
        for(int i=0;i<tentTemp.size();i++){
            tentacles[index].push_back(tentTemp[i]);
        }
        tentTemp.clear();
        index=(index+1)%p;
    }
}

int main(){
    int s;
    cin>>n>>m>>p;
    vector<pair<int,int> > tentacles[p];

    int cnt[p];
    for(int i=0;i<p;i++){
        cin>>s;
        cnt[i]=0;
        speed.push_back(s);
    }
    string g;
    for(int i=0;i<n;i++){
        cin>>g;
        grid.push_back(g);
        for(int j=0;j<m;j++){
            if(grid[i][j] != '.' && grid[i][j]!='#'){
                tentacles[(int)grid[i][j]-49].push_back(make_pair(i,j));
            }
        }
    }

    spreadTentacles(0,tentacles);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           //  cout<<grid[i][j]<<" ";
            if(grid[i][j] != '.' && grid[i][j]!='#'){

                cnt[(int)grid[i][j]-49]++;
            }
        }
        //cout<<"\n";
    }

    for(int i=0;i<p;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

