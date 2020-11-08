#include<bits/stdc++.h>

using namespace std;

int n,m;

struct node{
    int val;
    int inDegrees;
    int type;
    int power;
    vector<int> outDegrees;
    vector<int> equalDegrees;
};

struct node graph[2005];

void buildGraph(){
    int i=0;
    for(;i<n;i++){
        graph[i].val = i;
        graph[i].type = 1;
        graph[i].inDegrees = 0;
    }

    for(;i<n+m;i++){
        graph[i].val = i;
        graph[i].type = 2;
        graph[i].inDegrees = 0;
    }
}

void createDependency(int i, int j, char d){
    switch(d){
    case '<':
        graph[j].outDegrees.push_back(i);
        graph[i].inDegrees++;
        break;
    case '>':
        graph[i].outDegrees.push_back(j);
        graph[j].inDegrees++;
        break;
    case '=':
        graph[j].equalDegrees.push_back(i);
        graph[i].equalDegrees.push_back(j);
        break;
    default:
        break;
    }
}

bool isInDegreeZero(int root, int* has){

    if(graph[root].inDegrees!=0){
        has[root]=2;
        return false;
    }
    for(int i=0; i< graph[root].equalDegrees.size(); i++){
        if(has[graph[root].equalDegrees[i]]==0){
            has[graph[root].equalDegrees[i]]=1;
            if(!isInDegreeZero(graph[root].equalDegrees[i],has)){
                has[root]=2;
                return false;
            }
        }else if(has[graph[root].equalDegrees[i]]==2){
            has[root]=2;
            return false;
        }
    }
    return true;
}

void addToIndependents(int root, int* has, vector<int>& independents){
    independents.push_back(root);
    for(int i=0; i< graph[root].equalDegrees.size(); i++){
        if(has[graph[root].equalDegrees[i]]==0){
            has[graph[root].equalDegrees[i]]=1;
            addToIndependents(graph[root].equalDegrees[i],has,independents);
        }
    }
}

void removeDependency(int root, vector<int>& independents){
    int has[2005]={0};
    int has2[2005]={0};

    for(int j=0;j<graph[root].outDegrees.size();j++){
        int child = graph[root].outDegrees[j];
        graph[child].inDegrees--;
    }
    for(int j=0;j<graph[root].outDegrees.size();j++){
        int child = graph[root].outDegrees[j];

        if(has[child]==0){
            has[child]=1;
            if(isInDegreeZero(child,has)){
                has2[child]=1;
                addToIndependents(child,has2,independents);
            }
        }
    }
}

vector<int> topoSort(){
    vector<int> ans;
    vector<vector<int> > tempAns;
    vector<int> independents;
    vector<int> independents2;
    int has[2005]={0};
    int has2[2005]={0};

    for(int i=0;i<n+m;i++){
        if(has[i]==0){

            has[i]=1;
            if(isInDegreeZero(i,has)){
                has2[i]=1;
                addToIndependents(i,has2,independents);
            }
        }
    }

    int ctr=0,p=0;
    while(independents.size()>0 || independents2.size()>0){
        if(ctr==0){
            for(int i=0;i<independents.size();i++){
                removeDependency(independents[i], independents2);
            }
            tempAns.push_back(independents);
            independents.clear();
        }else{
            for(int i=0;i<independents2.size();i++){
                removeDependency(independents2[i], independents);
            }
            tempAns.push_back(independents2);
            independents2.clear();
        }
        ctr=1-ctr;
    }

    p=1;
    for(int i=tempAns.size()-1;i>=0;i--){
        for(int j=0;j<tempAns[i].size();j++){
            graph[tempAns[i][j]].power=p;
            ans.push_back(tempAns[i][j]);
        }
        p++;
    }
    return ans;
}

int main(){
    cin>>n>>m;

    buildGraph();

    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            createDependency(i,n+j,s[j]);
        }
    }


    int dishaPower[n];
    int dishbPower[m];

    vector<int> ans = topoSort();

    if(ans.size()<n+m){
        cout<<"No";
    }else{
        cout<<"Yes\n";
        for(int i=0;i<ans.size();i++){
            if(graph[ans[i]].type==1){
                dishaPower[graph[ans[i]].val]=graph[ans[i]].power;
            }else{
                dishbPower[graph[ans[i]].val-n]=graph[ans[i]].power;
            }
        }

        for(int i=0;i<n;i++){
            cout<<dishaPower[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<m;i++){
            cout<<dishbPower[i]<<" ";
        }
    }
    return 0;
}
