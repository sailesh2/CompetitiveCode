#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>  getHashIndex(string a, int n){
    vector<vector<int>> has;
    for(int i=0;i<20;i++){
        vector<int> v;
        has.push_back(v);
    }

    for(int i=0;i<n;i++){
        has[a[i]-'a'].push_back(i);
    }

    return has;
}

pair<vector<int>,char> removeUnwanted(vector<int> v, string a, string b){
    vector<int> filtered;
    char mini='z';
    for(int i=0;i<v.size();i++){
        if(a[v[i]]!=b[v[i]]){
            filtered.push_back(v[i]);

            mini=min(mini,b[v[i]]);
        }
    }

    return make_pair(filtered,mini);
}

vector<int>getTrans(vector<int> v, string b, char next){
    vector<int> nextV;

    for(int i=0;i<v.size();i++){
        if(b[v[i]]!=next){
            nextV.push_back(v[i]);
        }
    }

    return nextV;
}

int getMinTrans(string a, string b, int n){
    vector<vector<int>> has = getHashIndex(a,n);
    vector<int> v;
    int trans = 0;

    for(char c='a';c<='t';c++){
        v=has[c-'a'];
        pair<vector<int>,char> next=removeUnwanted(v,a,b);
        v=next.first;
        char nextC = next.second;

        if(nextC!='z'){
            v = getTrans(v,b,nextC);
            trans++;
            for(int i=0;i<v.size();i++){
                has[nextC-'a'].push_back(v[i]);
            }
        }
    }

    return trans;
}

bool possible(string a, string b, int n){
    for(int i=0;i<n;i++){
        if(a[i]>b[i])
            return false;
    }
    return true;
}

int main(){
    int t,n;
    string a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>a>>b;
        if(possible(a,b,n)){
            cout<<getMinTrans(a,b,n)<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
