#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    set<int> charPos[26];
    set<int>::iterator charPosItL;
    set<int>::iterator charPosItR;

    for(int i=0;i<s.length();i++){
        charPos[s[i]-'a'].insert(i);
    }

    int q,type,pos,l,r;
    char c;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>type;
        if(type==1){
            cin>>pos>>c;
            pos--;
            charPos[s[pos]-'a'].erase(charPos[s[pos]-'a'].find(pos));
            s[pos]=c;
            charPos[c-'a'].insert(pos);
        }else{
            cin>>l>>r;
            l--;
            r--;
            int ctr=0;
            for(int j='a';j<='z';j++){
                charPosItL =charPos[j-'a'].lower_bound(l);
                if(charPosItL!=charPos[j-'a'].end() && *charPosItL<=r){
                    ctr++;
                }
            }
            cout<<ctr<<"\n";
        }
    }
    return 0;
}
