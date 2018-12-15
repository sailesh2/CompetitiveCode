#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        int has[500]={0};
        string ans="";
        for(int i=0;i<S.length();i++){
            for(int j=0;j<T.length();j++){
                if(T[j]==S[i]){
                    ans=ans+S[i];
                    has[j]=1;
                }
            }
        }
        for(int i=0;i<T.length();i++){
            if(has[i]==0){
                ans=ans+T[i];
            }
        }
        return ans;
    }
};
