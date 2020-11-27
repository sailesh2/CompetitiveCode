#include<bits/stdc++.h>
#define gc getchar

using namespace std;

int has[150005]={0};
int ctr[150005]={0};

vector<int> linkedList[150005];

inline int lscan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

void insertDisjointSet(int x, int y){
    int ctr1=0,ctr2=0;

    while(has[x]!=0){
        x=has[x];
    }
    while(has[y]!=0){
        y=has[y];
    }

    if(x==y)
        return;
    ctr1=ctr[x];
    ctr2=ctr[y];

    if(ctr1 >= ctr2){
        linkedList[x].push_back(y);
        has[y]=x;
        ctr[x]=max(ctr[x],ctr[y]+1);
    }else{
        linkedList[y].push_back(x);
        has[x]=y;
        ctr[y]=max(ctr[y],ctr[x]+1);
    }
}

int getStart(int v){
    while(has[v]!=0){
        v=has[v];
    }
    return v;
}

void traverse(int start){
    vector<int> v = linkedList[start];
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        traverse(v[i]);
    }
}

int main(){
    int n;
    n=lscan();
    int x,y;
    for(int i=0;i<n-1;i++){
        x=lscan();
        y=lscan();
        insertDisjointSet(x,y);
    }

    int start = getStart(1);
    cout<<start<<" ";
    traverse(start);
    return 0;
}
