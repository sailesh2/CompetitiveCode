#include<bits/stdc++.h>

using namespace std;

string player[2];


string winner(string s){
    int ctr=1;
    vector<char> stk;

    for(int i=0;i<s.length();i++){
        if(stk.size()==0){
            stk.push_back(s[i]);
        }else{
            if(stk[stk.size()-1]==s[i]){
                stk.push_back(s[i]);
            }else{
                stk.pop_back();
                ctr++;
            }
        }
    }

    return player[ctr%2];
}

int main(){
    player[0]="DA";
    player[1]="NET";
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<winner(s)<<"\n";
    }
    return 0;
}
