#include<bits/stdc++.h>

using namespace std;

string removeEven(string s){
    string formatted="";
    for(int i=0;i<s.length();i=i+2){
        if(s[i]!=s[i+1]){
            formatted.push_back(s[i]);
            formatted.push_back(s[i+1]);
        }
    }

    return formatted;
}

string removeOdd(string s){
    string formatted="";
    int save=0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]){
            save=i;
            break;
        }
    }
    for(int i=0;i<s.length();i++){
        if(i!=save)
            formatted.push_back(s[i]);
    }

    return formatted;
}

int main(){
    int n;
    cin>>n;
    string s;
    string orig;
    cin>>s;
    orig=s;
    if(n%2!=0){
        s=removeOdd(s);
    }
    s=removeEven(s);
    cout<<orig.length()-s.length()<<"\n";
    cout<<s;

    return 0;
}
