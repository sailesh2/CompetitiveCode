#include<bits/stdc++.h>

using namespace std;

char getDifCol(char a, char b){
    if(a=='R'){
        if(b=='G')
            return 'B';
        else
            return 'G';
    }else if(a=='B'){
        if(b=='G')
            return 'R';
        else
            return 'G';
    }else{
        if(b=='R')
            return 'B';
        else
            return 'R';

    }
}

char getDifCol(char a){
    if(a=='R')
        return 'B';
    else if(a=='B')
        return 'R';
    else
        return 'R';
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ctr=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            if(i<n){
                s[i]=getDifCol(s[i-1],s[i+1]);
            }else{
                s[i]=getDifCol(s[i-1]);
            }
            ctr++;
        }
    }
    cout<<ctr<<"\n";
    cout<<s;
    return 0;
}
