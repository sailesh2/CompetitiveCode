#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int maxi[2];
    maxi[0]=0;
    maxi[1]=0;
    vector<char> stk;
    char save='2';

    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(stk.size()==0){
                stk.push_back(s[i]);
                save=s[i];
            }else{
                if(stk[stk.size()-1]==s[i]){
                    stk.push_back(s[i]);
                 }
                else{
                    stk.pop_back();
                 }
            }

            maxi[save-'0']=max(maxi[save-'0'],(int)stk.size());
        }
    }

    if(stk.size()==0){
        cout<<maxi[0]+maxi[1];
    }
    else
        cout<<"-1";
    return 0;
}
