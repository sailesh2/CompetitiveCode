#include<bits/stdc++.h>

using namespace std;

map<int,int> posCount;
map<int,int>::iterator posCountIt;
vector<int> neg;
int zero,n;

bool isValid(char *stk, int l){
    char f;
    for(int i=0;i<l;i++){
        if(i==0)
        {
            f=stk[i];
        }else{
            if(f!=stk[i]){
                return false;
            }
        }
    }
    return true;
}
void store(string s){
    char stk[s.length()];
    int top=-1;
    int ctr=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            ctr++;
            stk[++top]=s[i];
        }
        else
        {
            ctr--;
            if(top>=0 && stk[top]=='('){
                top--;
            }
            else{
                stk[++top]=')';
            }
        }
    }

    if(isValid(stk, top+1)){
        if(ctr>0){
            posCountIt = posCount.find(ctr);
            int c=0;
            if(posCountIt != posCount.end()){
                c=posCountIt->second;
                posCount.erase(posCountIt);
            }
            c++;
            posCount.insert(make_pair(ctr,c));
        }else if(ctr<0){
            neg.push_back(-1*ctr);
        }else{
            zero++;
        }
    }
}
int main(){
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        store(s);
    }
    int ans=0;
    for(int i=0;i<neg.size();i++){
        posCountIt = posCount.find(neg[i]);

        if(posCountIt != posCount.end()){
            int c = posCountIt->second;
            c--;
            posCount.erase(posCountIt);
            if(c>0)
                posCount.insert(make_pair(neg[i],c));
            ans++;
        }
    }
    cout<<ans+zero/2;
    return 0;
}
