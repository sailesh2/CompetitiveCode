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

    set<int> taken;

    int stk[3][n];
    int top[3];
    top[0]=-1;
    top[1]=-1;
    top[2]=-1;

    vector<char> notTaken[3];


    int pos,val,next;
    for(int i=0;i<q;i++){
        cin>>op;
        if(op=='+'){
            cin>>religion>>letter;
            religion--;

            if(notTaken[religion].size()>0){
                notTaken[religion].push_back(letter);
            }else{
                if(top[religion]==-1){
                    next=0;
                }else{
                    next=stk[religion][top[religion]];
                }

            //    cout<<"NEXT-"<<next<<"\n";

                while(1){
                    val=dp[next][letter-'a'];
                    if(val==-1 || taken.count(val)==0)
                        break;
                    next=val;
                }
            //    cout<<"VAL-"<<val<<"\n";

                if(val==-1){
                    notTaken[religion].push_back(letter);
                }else{
                    taken.insert(val);
                    top[religion]++;
                    stk[religion][top[religion]]=val;
                }
            }


            if(notTaken[0].size()==0 && notTaken[1].size()==0 && notTaken[2].size()==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }else{
            cin>>religion;
            religion--;
            if(notTaken[religion].size()>0){
                notTaken[religion].pop_back();
            }else{
                val=stk[religion][top[religion]];
                taken.erase(val);
                top[religion]--;

            }


            for(int j=0;j<3;j++){
                int start=0;
                int k;
                for(k=0;k<notTaken[j].size();k++){
                    char l = notTaken[j][k];
                    while(1){
                        start=dp[start][l-'a'];

                        if(start==-1 || taken.count(start)==0){
                            break;
                        }
                    }

                    if(start!=-1){
                        top[j]++;
                        stk[j][top[j]]=start;
                        taken.insert(start);
                    }else{
                        break;
                    }
                }

                //cout<<j<<" "<<k<<"\n";
                vector<char> tempNotTaken;
                for(;k<notTaken[j].size();k++){
                    tempNotTaken.push_back(notTaken[j][k]);
                }
                notTaken[j].clear();
                for(int m=0;m<tempNotTaken.size();m++){
                    notTaken[j].push_back(tempNotTaken[m]);
                }
            }

            if(notTaken[0].size()==0 && notTaken[1].size()==0 && notTaken[2].size()==0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }

        }
    }
    return 0;
}
