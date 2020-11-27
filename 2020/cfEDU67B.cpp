#include<bits/stdc++.h>

using namespace std;
int n;

vector<int> preStore[300];

void storePre(string s){
    for(int i=0;i<n;i++){
        preStore[s[i]].push_back(i+1);
    }
}

int findPrePos(string f){
    int has[300]={0};
    for(int i=0;i<f.length();i++){
        has[f[i]]++;
    }
    int maxi=0;
    for(char c='a';c<='z';c++){
        if(has[c]>0){
            maxi=max(maxi,preStore[c][has[c]-1]);
        }
    }

    return maxi;
}

int main(){
    cin>>n;
    string s;
    cin>>s;

    storePre(s);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        string f;
        cin>>f;
        cout<<findPrePos(f)<<"\n";
    }
    return 0;
}
