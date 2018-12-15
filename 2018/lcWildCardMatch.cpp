#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int** notMatch;
    void preprocess(int sl,int pl){
        notMatch = new int*[sl];
        for(int i = 0; i < sl; ++i)
            notMatch[i] = new int[pl];

        for(int i=0;i<sl;i++){
            for(int j=0;j<pl;j++){
                notMatch[i][j]=0;
            }
        }
    }
    bool isMatchDP(int si,int pi,string s,string p){
        if(si==s.length() || pi==p.length()){
            if( si==s.length() && pi==p.length()){
                return true;
            }else if(si==s.length()){
                int cnt=0;
                for(int i=pi;i<p.length();i++){
                    if(p[i]!='*'){
                        cnt=1;
                        break;
                    }
                }
                return cnt==0;
            }else{
                int cnt=0;
                for(int i=si;i<s.length();i++){
                    if(s[i]!='*'){
                        cnt=1;
                        break;
                    }
                }
                return cnt==0;
            }
        }

        if(s[si]!='*' && p[pi]!='*'){
            if(s[si]!='?' && p[pi]!='?'){
                if(s[si]==p[pi]){
                    if(notMatch[si+1][pi+1]==0)
                        return isMatchDP(si+1,pi+1,s,p);
                }
            }else{
                if(notMatch[si+1][pi+1]==0)
                    return isMatchDP(si+1,pi+1,s,p);
            }
        }else if(s[si]=='*' && p[pi]=='*'){
            for(int i=pi;i<=p.length();i++){
                if(notMatch[si+1][i]==0){
                    if(isMatchDP(si+1,i,s,p))
                        return true;
                }
            }
            for(int i=si;i<=s.length();i++){
                if(notMatch[i][pi+1]==0){

                    if(isMatchDP(i,pi+1,s,p))
                        return true;
                }
            }
        }else if(s[si]=='*'){
            for(int i=pi;i<=p.length();i++){
                if(notMatch[si+1][i]==0){

                    if(isMatchDP(si+1,i,s,p))
                        return true;
                }
            }
        }else{
            for(int i=si;i<=s.length();i++){
                if(notMatch[i][pi+1]==0){

                    if(isMatchDP(i,pi+1,s,p))
                        return true;
                }
            }
        }
        notMatch[si][pi]=1;
        return false;
    }
public:
    bool isMatch(string s, string p) {
        preprocess(s.length(),p.length());
        return isMatchDP(0,0,s,p);
    }
};
