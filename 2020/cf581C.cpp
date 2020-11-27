#include<bits/stdc++.h>

using namespace std;
int MAX=1000000000;
int pathWeight[1005][1005];
int n,m;

void warshall(string* adj){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]=='1')
            pathWeight[i][j]=1;
            else
            pathWeight[i][j]=MAX;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        if((pathWeight[i][k]+pathWeight[k][j])<pathWeight[i][j]){
                            pathWeight[i][j]=pathWeight[i][k]+pathWeight[k][j];
                        }
                    }
                }
            }else{
                pathWeight[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        if((pathWeight[i][k]+pathWeight[k][j])<pathWeight[i][j]){
                            pathWeight[i][j]=pathWeight[i][k]+pathWeight[k][j];
                        }
                    }
                }
            }else{
                pathWeight[i][j]=0;
            }
        }
    }
}

vector<int> rev(vector<int> v){
    vector<int> rv;
    for(int i=v.size()-1;i>=0;i--)
        rv.push_back(v[i]);

    return rv;
}

vector<int> shortestSubSequence(int* path){
    vector<int> sp;
    sp.push_back(path[m-1]);
    int ctr=2;
    for(int i=m-2;i>0;i--){
        if(pathWeight[path[i-1]][sp[sp.size()-1]]>=ctr){
            ctr++;
        }else{
            ctr=2;
            sp.push_back(path[i]);
        }
    }
    sp.push_back(path[0]);
    return rev(sp);
}

void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<pathWeight[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    cin>>n;
    string adj[n];
    for(int i=0;i<n;i++){
        cin>>adj[i];
    }

    cin>>m;
    int path[m];
    for(int i=0;i<m;i++){
        cin>>path[i];
        path[i]--;
    }

    warshall(adj);

    vector<int> shortSubSeq = shortestSubSequence(path);

    cout<<shortSubSeq.size()<<"\n";
    for(int i=0;i<shortSubSeq.size();i++){
        cout<<1+shortSubSeq[i]<<" ";
    }
    return 0;
}
