#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string createPart(string s, int odd){
    string p="";
    int mid = odd ? s.length()/2 + 1 : s.length()/2;
    for(int i=0;i<mid;i++){
        p.push_back(s[i]);
    }
    return p;
}

bool oddPassed=false;

int parts(string s){
    //cout<<s<<"\n"<<s.length();
    if(s.length()==1)
        return 0;
    if(!isPalindrome(s))
        return oddPassed ? 2 : 1;
    if(s.length()%2!=0){
        oddPassed=true;
        if(!isPalindrome(createPart(s,true))){
            return 2;
        }
    }
    return parts(createPart(s,false));
}

int main(){
    string s;
    cin>>s;
    int ps=parts(s);
    if(ps==0)
    cout<<"Impossible";
    else
    cout<<ps;
    return 0;
}
