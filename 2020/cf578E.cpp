#include<bits/stdc++.h>

using namespace std;

bool isSuffixEqualPrefix(string& compressedWord, string& w, int pos){
    int l=compressedWord.length();
    l=l-pos-1;

    for(int i=0;i<=pos;i++){
        if(w[i]!=compressedWord[l+i]){
            return false;
        }
    }
    return true;
}

int binSear(string& compressedWord, string& w){
    int ctr=1;
    int save=-1;
    int save2=-1;
    int k=w.length();

    while(1){
        while(save+ctr<k && isSuffixEqualPrefix(compressedWord,w,save+ctr)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+1;
}

int main(){
    int n;
    cin>>n;
    vector<string> words;
    string compressedWord="";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        words.push_back(s);
        if(i==0)
            compressedWord=s;
    }

    for(int i=1;i<n;i++){
        string w = words[i];
        int start = binSear(compressedWord, w);
        for(int j=start;j<w.length();j++){
            compressedWord.push_back(w[j]);
        }
    }

    cout<<compressedWord;
    return 0;
}
