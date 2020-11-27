#include<bits/stdc++.h>

using namespace std;

bool isOK(string s){
    for(int i=1;i<s.length();i++){
        if(abs(s[i]-s[i-1])==1){
            return false;
        }
    }
    return true;
}

string getDuplicateLetters(string s, int* ctr){
    string sdup="";

    for(int i=0;i<s.length();i++){
        for(int j=0;j<ctr[s[i]];j++){
            sdup.push_back(s[i]);
        }
    }
    return sdup;
}

string putLastIntoFirst(string s){
    string s1="";
    s1.push_back(s[s.length()-1]);
    for(int i=0;i<s.length()-1;i++){
        s1.push_back(s[i]);
    }
    return s1;
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        int len=s.length();
        sort(s.begin(),s.end());
        string sd="";
        int ctr[300]={0};
        for(int j=0;j<len;j++){
            if(ctr[s[j]]==0){
                sd.push_back(s[j]);
            }
            ctr[s[j]]++;
        }
        string s1="";
        int l=0,r=sd.length()-1;
        while(l<r){
            s1.push_back(sd[l]);
            s1.push_back(sd[r]);
            l++;
            r--;
        }
        if(l==r)
            s1.push_back(sd[l]);

        if(!isOK(s1)){
            s1=putLastIntoFirst(s1);
        }
        if(isOK(s1)){

            s1=getDuplicateLetters(s1,ctr);
            cout<<s1<<"\n";
        }else{
            cout<<"No answer\n";
        }
    }
    return 0;
}
