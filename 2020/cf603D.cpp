#include<bits/stdc++.h>

using namespace std;

int ctr=0;
int cnt[300]={0};
int taken[300]={0};
int n;
int has[200005][27]={0};
vector<string> pass;
void check(char ch){

        if(cnt[ch]==0){
            for(int i=0;i<n;i++){
                if(has[i][ch-'a']==1){
                    ctr++;
                    cnt[ch]=ctr;
                    break;
                }
            }
        }
        vector<char> next;
        if(cnt[ch]>0){
            for(int i=0;i<n;i++){
                string s=pass[i];
                if(has[i][ch-'a']==1){
                    for(int j=0;j<s.length();j++){
                        cnt[s[j]]=cnt[ch];
                        if(taken[s[j]]==0){
                            taken[s[j]]=1;
                            next.push_back(s[j]);
                        }
                    }
                }
            }
        }

        for(int i=0;i<next.size();i++)
            check(next[i]);
}
int main(){
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        pass.push_back(s);
        for(int j=0;j<pass[i].length();j++){
            has[i][pass[i][j]-'a']=1;
        }
    }
    for(char ch='a';ch<='z';ch++){
        if(taken[ch]==0){
            taken[ch]=1;
            check(ch);
        }
    }
    cout<<ctr;
    return 0;
}
