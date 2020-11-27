#include<bits/stdc++.h>

using namespace std;

int allSame(string s, char f, char l, int index){

    int n=s.length();
    int ctr=0;
    for(int i=0;i<=index;i++){
        if(s[i]!=f)
            ctr++;
    }

    for(int i=index+1;i<n;i++){
        if(s[i]!=l)
            ctr++;
    }

    return ctr;
}

int minOps(string s){
    int n=s.length();
    int mini=n;
    for(int i=-1;i<n;i++){
        mini=min(mini,allSame(s,'0','1',i));
    }

    for(int i=-1;i<n;i++){
        mini=min(mini,allSame(s,'1','0',i));
    }

    return mini;
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<minOps(s)<<"\n";
    }
    return 0;
}
