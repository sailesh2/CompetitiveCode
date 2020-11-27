#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int maxi=0;
    vector<char> stk;
    char save='2';
    int ctr=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(stk.size()==0){
                stk.push_back(s[i]);
                if(save=='2')
                    save=s[i];
                if(save==stk[0])
                    ctr++;
                save=stk[0];
            }else{
                if(stk[stk.size()-1]==s[i]){
                    stk.push_back(s[i]);
                    if(save==s[i])
                        ctr++;
                    save=s[i];
                }
                else{
                    stk.pop_back();
                    save=s[i];
                }
            }
        }
    }

    if(stk.size()==0)
        cout<<ctr;
    else
        cout<<"-1";
    return 0;
}
