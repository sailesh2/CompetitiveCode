#include<bits/stdc++.h>

using namespace std;

string rev(string s){
    string srev="";
    for(int i=s.length()-1;i>=0;i--)
        srev.push_back(s[i]);
    return srev;
}

bool isPalindrome(string s1, string s2){
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i])
            return false;
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;

    bool palindrome[n];
    set<string> exists;

    string s;
    vector<string> first;
    vector<string> second;

    string strs[n];
    set<string> taken;
    for(int i=0;i<n;i++){
        cin>>s;
        string srev = rev(s);
        palindrome[i] = isPalindrome(s,srev);

        if(exists.count(srev)>0){
            first.push_back(s);
            second.push_back(srev);
            taken.insert(s);
            taken.insert(srev);
        }
        exists.insert(s);

        strs[i]=s;
    }

    for(int i=0;i<n;i++){
        s=strs[i];
        if(palindrome[i] && taken.count(s)==0){
            first.push_back(s);
            break;
        }
    }

    int l=first.size() + second.size();
    cout<<l*m<<"\n";
    for(int i=0;i<first.size();i++){
        cout<<first[i];
    }
    for(int i=second.size()-1;i>=0;i--){
        cout<<second[i];
    }

    return 0;
}
