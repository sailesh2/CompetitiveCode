#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int p[n],c[n];

        int has[n];
        for(int j=0;j<n;j++){
            cin>>p[j];
            has[i]=0;
        }
        for(int j=0;j<n;j++){
            cin>>c[j];
        }

        vector<vector<int>> chains;
        for(int j=0;j<n;i++){
            v=j;
            if(has[v]==0){
                vector<int> chain;
                while(1){
                    chain.push_back(v);
                    has[v]=1;
                    v=p[v]-1;
                    if(v==j)
                        break;
                }
                chains.push_back(chain);
            }
        }

        for(int j=0;j<chains.size();j++){
            int cs = chains[j].size();


        }
    }
    return 0;
}
