#include<bits/stdc++.h>

using namespace std;
string noLetTaken(string s){
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]!='?' && s[i]!='*')
            ans=ans+s[i];
    }
    return ans;
}

string addLetter(string s, int k, int let, int star){

    int letReq = k-let;
    int letReqC=0;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(i==star-1){
            while(letReqC<letReq){
                ans=ans+s[i];
                letReqC++;
            }
            ans=ans+s[i];
        }else{
            if(s[i]!='?' && s[i]!='*')
            ans=ans+s[i];
        }
    }
    return ans;
}

string letterTaken(string s, set<int> candySet, int k,int let){
    vector<char> ans;
    int letTaken=0;
    for(int i=0;i<s.length();i++){
        if(candySet.count(i)>0 && letTaken<let-k){
            letTaken++;
            ans.pop_back();
        }else{
            if(s[i]!='?' && s[i]!='*')
                ans.push_back(s[i]);
        }
    }
    string ansS="";
    for(int i=0;i<ans.size();i++){
        ansS=ansS+ans[i];
    }
    return ansS;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    set<int> takenSet;
    int candy=-1,star=-1,let=0,c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='?'){
            candy=i;
            takenSet.insert(i);
            c++;
        }
        else if(s[i]=='*'){
            takenSet.insert(i);
            star=i;
            c++;
        }
        else
            let++;
    }


    if(let==k){
        cout<<noLetTaken(s);
    }else if(let<k){
        if(star==-1){
            cout<<"Impossible";
        }else{
            cout<<addLetter(s,k,let,star);
        }
    }else{
        if(let-k<=c){
            cout<<letterTaken(s,takenSet,k,let);
        }else{
            cout<<"Impossible";
        }
    }
}
