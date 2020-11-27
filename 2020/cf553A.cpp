#include<bits/stdc++.h>

using namespace std;
int minExchange(string s){
    //cout<<s;
    return min( (s[0]-'A'+26)%26, ('A'-s[0]+26)%26)
    + min( (s[1]-'C'+26)%26, ('C'-s[1]+26)%26)
    + min( (s[2]-'T'+26)%26, ('T'-s[2]+26)%26)
    + min( (s[3]-'G'+26)%26, ('G'-s[3]+26)%26);
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mini=10000000;
    for(int i=0;i<n;i++){
        string sub="";
        for(int j=i;j<i+4 && j<n;j++){
            sub.push_back(s[j]);
        }
        if(sub.length()==4)
        mini=min(mini,minExchange(sub));
    }
    cout<<mini;
    return 0;
}
