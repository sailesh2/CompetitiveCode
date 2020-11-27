#include<bits/stdc++.h>

using namespace std;

bool isOpposite(char a, char b){
    return (a=='w' && b=='b') || (a=='b' && b=='w');
}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int ctr=1;
    int maxi=1;
    for(int i=0;i<n-1;i++){
        if(isOpposite(s[i],s[i+1])){
            ctr++;
            maxi=max(maxi,ctr);
        }else{
            ctr=1;
        }
    }

    ctr=1;
    int save=0;
    for(int i=0;i<n-1;i++){
        save=i;
        if(isOpposite(s[i],s[i+1])){
            ctr++;
        }else{
            break;
        }
        save=i+1;
    }

    if(isOpposite(s[0],s[n-1]) && n-1>save){
        ctr++;
    for(int i=n-1;i>save;i--){
        if(isOpposite(s[i],s[i-1])){
            ctr++;
        }else{
            break;
        }
    }
    }

    maxi=max(maxi,ctr);
    cout<<maxi;
    return 0;
}
