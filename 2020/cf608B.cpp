#include<bits/stdc++.h>

using namespace std;
int n;

char invertColor(char c){
    if(c=='B')
        return 'W';
    else
        return 'B';
}

pair<bool,vector<int> > canBeSingleColor(string s, char col){

    vector<int> v;
    for(int i=0;i<n-1;i++){
        if(s[i]==col){
            s[i]=invertColor(s[i]);
            v.push_back(i+1);
            s[i+1]=invertColor(s[i+1]);
        }
    }
    if(s[n-1]==s[0])
        return make_pair(true,v);
    else
        return make_pair(false,v);
}
pair<bool,vector<int> > canBeSingleColor(string s){

    pair<bool,vector<int> > p1=canBeSingleColor(s,'B');
    if(p1.first)
        return p1;
    p1=canBeSingleColor(s,'W');
    return p1;
}

int main(){
    cin>>n;
    string s;
    cin>>s;
    pair<bool,vector<int> > v=canBeSingleColor(s);
    if(v.first){
        cout<<v.second.size()<<"\n";
        for(int i=0;i<v.second.size();i++){
            cout<<v.second[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    return 0;
}
