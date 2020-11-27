#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> dsuGrid;
int parent[1000005];
int height[1000005]={0};
int compId=0;

void setup(){
    for(int i=0;i<1000005;i++)
        parent[i]=-1;
}

int getDsuValue(int x, int y){

    while(parent[x]!=-1){
        x=parent[x];
    }
    while(parent[y]!=-1){
        y=parent[y];
    }

    if(height[x]>height[y]){
        parent[y]=x;
        return x;
    }else if(height[x]<height[y]){
        parent[x]=y;
        return y;
    }else{
        parent[y]=x;
        height[x]++;
        return x;
    }
}

int getDsuValue(int x){

    while(parent[x]!=-1){
        x=parent[x];
    }

    return x;
}

int getDsuValue(int r, int c, vector<int>* evenOdd){

    if(r==0 && c==0){
        return compId++;
    }

    if(r==0 && c>0){
        return (evenOdd[r][c-1]==evenOdd[r][c])?getDsuValue(dsuGrid[r][c-1]):(compId++);
    }

    if(c==0 && r>0){
        return (evenOdd[r-1][c]==evenOdd[r][c])?getDsuValue(dsuGrid[r-1][c]):(compId++);
    }

    if(evenOdd[r-1][c] == evenOdd[r][c] && evenOdd[r][c-1]==evenOdd[r][c]){
        return getDsuValue(dsuGrid[r-1][c],dsuGrid[r][c-1]);
    }
    else if(evenOdd[r-1][c] == evenOdd[r][c]){
        return getDsuValue(dsuGrid[r-1][c]);
    }
    else if(evenOdd[r][c-1]==evenOdd[r][c]){
        return getDsuValue(dsuGrid[r][c-1]);
    }else{
        return compId++;
    }
}


bool allSurroundingEven(vector<int>* evenOdd){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(evenOdd[i][j]==0 && (i-1)>=0 && (j-1)>=0 && (i+1)<(n-1) && (j+1)<(m-1)){
                int z=0;
                z=z+evenOdd[i-1][j];
                z=z+evenOdd[i][j-1];
                z=z+evenOdd[i+1][j];
                z=z+evenOdd[i][j+1];

                if(z%2==0)
                    return true;
            }
        }
    }
    return false;
}


void storeDsu(vector<int>* evenOdd){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(evenOdd[i][j]==0){
                dsuGrid[i][j]=getDsuValue(i,j,evenOdd);
                if(height[dsuGrid[i][j]]==0)
                    height[dsuGrid[i][j]]=1;
            }
        }
    }
}

int calOps(vector<int>* evenOdd){
    int compCtr[1000005]={0};
    vector<int> components;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            if(evenOdd[i][j]==0){
                int dv = getDsuValue(dsuGrid[i][j]);
                if(compCtr[dv]==0){
                    components.push_back(dv);
                }
                compCtr[dv]++;
            }
        }
    }
    int ctr=0;
    for(int j=0;j<components.size();j++){
        int i=components[j];
        ctr=ctr+compCtr[i]/2 + compCtr[i]%2;
    }

    return ctr;
}

int main(){
    cin>>n>>m;

    string grid[n];
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    if(n==1 || m==1)
        cout<<"0";
    else{
        int cnt=0;
        vector<int> evenOdd[n-1];
        for(int i=0;i<n-1;i++){
            vector<int> v,v1;
            for(int j=0;j<m-1;j++){
                int z=0;
                if(grid[i][j]=='0')
                    z++;

                if(grid[i+1][j]=='0')
                    z++;

                if(grid[i][j+1]=='0')
                    z++;

                if(grid[i+1][j+1]=='0')
                    z++;

                if(z%2==0)
                    v.push_back(0);
                else
                    v.push_back(1);

                v1.push_back(-1);



            }

            evenOdd[i]=v;
            dsuGrid.push_back(v1);
        }

        if(allSurroundingEven(evenOdd))
            cout<<"-1\n";
        else{
            setup();
            storeDsu(evenOdd);
            cout<<calOps(evenOdd);
        }
    }
    return 0;
}
