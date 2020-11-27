#include<bits/stdc++.h>

using namespace std;

char getDiff(char f, char s){
    if(f=='a' && s=='b'){
        return 'c';
    }
    if(f=='b' && s=='a'){
        return 'c';
    }
    if(f=='a' && s=='c'){
        return 'b';
    }
    if(f=='c' && s=='a'){
        return 'b';
    }
    if(f=='b' && s=='c'){
        return 'a';
    }
    if(f=='c' && s=='b'){
        return 'a';
    }
}

char getDiff(char f){
    if(f=='a' || f=='c')
        return 'b';
    return 'a';
}

bool isBeautiful(string s){
    for(int i=0;i<s.length();i++){
        if(i+1<s.length() && s[i]==s[i+1])
            return false;
    }
    return true;
}

string beautiful(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='?'){
            if(i-1>=0 && s[i-1]!='?' && i+1<s.length() && s[i+1]!='?'){
                if(s[i-1]==s[i+1]){
                    s[i] = getDiff(s[i-1]);
                }else{
                    s[i]=getDiff(s[i-1],s[i+1]);
                }
            }else if(i-1>=0 && s[i-1]!='?'){
                s[i]=getDiff(s[i-1]);

            }else if(i+1<s.length() && s[i+1]!='?'){
                s[i]=getDiff(s[i+1]);
            }else{
                s[i]='a';
            }
        }
    }
    return s;
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        string b=beautiful(s);
        if(isBeautiful(b)){
            cout<<b<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}
