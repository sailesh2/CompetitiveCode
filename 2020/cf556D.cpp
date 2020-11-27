#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    string universeWord;
    cin>>universeWord;

    int dp[n+1][26];
    int temp[26];
    for(int j=0;j<26;j++){
        temp[j]=-1;
    }
    for(int i=n;i>0;i--){
        for(int j=0;j<26;j++){
            dp[i][j]=temp[j];
        }

        temp[universeWord[i-1]-'a']=i;
    }
    for(int j=0;j<26;j++){
        dp[0][j]=temp[j];
    }

    char op,letter;
    int religion;

    int stk[3][n];
    int top[3];
    top[0]=-1;
    top[1]=-1;
    top[2]=-1;
    int pos,val,next;
    for(int i=0;i<q;i++){
        cin>>op;
        if(op=='+'){
            cin>>religion>>letter;
            religion--;
            if(top[religion]==-1){
                next=0;
            }else{
                next=stk[religion][top[religion]];
            }

        //    cout<<"NEXT-"<<next<<"\n";

            val=dp[next][letter-'a'];
        //    cout<<"VAL-"<<val<<"\n";

            if(val==-1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                top[religion]++;
                stk[religion][top[religion]]=val;
                if(dp[0][letter-'a']==val)
                    dp[0][letter-'a']=dp[val][letter-'a'];
                for(int j=0;j<3;j++){
                    if(j!=religion && top[j]>-1){
                        if(stk[j][top[j]]<val){
                            pos=stk[j][top[j]];
                            if(dp[pos][letter-'a']==val){
                                dp[pos][letter-'a']=dp[val][letter-'a'];
                            }
                        }
                    }
                }
            }

        }else{
            cin>>religion;
            religion--;
            if(top[religion]==-1){
                cout<<"NO\n";
            }else{
            cout<<"YES\n";
            val=stk[religion][top[religion]];
            letter=universeWord[val-1];
            top[religion]--;
            if(dp[0][letter-'a']>val || dp[0][letter-'a']==-1)
                dp[0][letter-'a']=val;
            for(int j=0;j<3;j++){
                if(j!=religion && top[j]>-1){
                    if(stk[j][top[j]]<val){
                        pos = stk[j][top[j]];
                        if(dp[pos][letter-'a']>val || dp[pos][letter-'a']==-1){
                            dp[pos][letter-'a']=val;
                        }
                    }
                }
            }
            }
        }
    }
    return 0;
}
