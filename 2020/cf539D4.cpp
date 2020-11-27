#include<bits/stdc++.h>

using namespace std;

string createPart(string s){
    string p="";
    int mid = s.length()/2;
    for(int i=0;i<mid;i++){
        p.push_back(s[i]);
    }
    return p;
}

bool areAllCharSame(string s){
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1])
            return false;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int ans = s.length()%2==0 ? 1 : 2;
    if(areAllCharSame(createPart(s)))
    cout<<"Impossible";
    else
    cout<<ans;
    return 0;
}
