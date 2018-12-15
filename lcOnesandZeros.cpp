#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp[602][102][102];
    vector<pair<int,int> > inp;
    int tot,m1,n1;

    void clearDP(){
        for(int i=0;i<=tot;i++){
            for(int j=0;j<=m1;j++){
                for(int k=0;k<=n1;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    pair<int,int> countOneZero(string s){
        int one=0,zero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                one++;
            else
                zero++;
        }
        return make_pair(zero,one);
    }

    int findMaxFormDP(int ind,int m,int n){
        if(ind==tot){
            return 0;
        }
        int a=0,b=0;
        pair<int,int> p=inp[ind];
        if(m>=p.first && n>=p.second){
            if(dp[ind+1][m-p.first][n-p.second]!=-1){
                a=dp[ind+1][m-p.first][n-p.second];
            }else{
                a=findMaxFormDP(ind+1,m-p.first,n-p.second);
            }
            a++;
        }
        if(dp[ind+1][m][n]!=-1){
            b=dp[ind+1][m][n];
        }else{
            b=findMaxFormDP(ind+1,m,n);
        }
        dp[ind][m][n]=max(a,b);
        return dp[ind][m][n];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        tot=strs.size();
        for(int i=0;i<tot;i++){
            inp.push_back(countOneZero(strs[i]));
        }
        m1=m;
        n1=n;
        clearDP();
        return findMaxFormDP(0,m,n);
    }
};
