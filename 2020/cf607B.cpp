#include<bits/stdc++.h>

using namespace std;

int getMinChar(string s, string p){
    int pos=0;
    char mini='Z';
    for(int i=0;i<s.length();i++){
        if(s[i]<=mini){
            mini=s[i];
            pos=i;
        }
    }
    return pos;
}

bool isSmaller(string s, string p){
    int l=min(s.length(),p.length());
    for(int i=0;i<l;i++){
        if(s[i]<p[i])
            return true;
        else if(s[i]>p[i])
            return false;
    }

    return s.length()<p.length();
}

string strictSmall(string s, string p){
    //int c = getMinChar(s,p);

    pair<char,int> mins[s.length()];
    for(int i=s.length()-1;i>=0;i--){
        if(i==s.length()-1){
            mins[i]=make_pair(s[i],i);
        }else{
            if(s[i]<mins[i+1].first){
                mins[i]=make_pair(s[i],i);
            }else{
                mins[i]=mins[i+1];
            }
        }
    }

    int l=min(s.length(),p.length());

    for(int i=0;i<l;i++){
        if(s[i]>p[i]){
            if(mins[i].first<p[i]){
                char temp=s[i];
                s[i]=mins[i].first;
                s[mins[i].second]=temp;
                return s;
            }else if(mins[i].first==p[i]){
                char temp=s[i];
                s[i]=mins[i].first;
                s[mins[i].second]=temp;
                break;
            }
            else{
                return "---";
            }
        }else if(s[i]==p[i]){
            if(mins[i].first<p[i]){
                char temp=s[i];
                s[i]=mins[i].first;
                s[mins[i].second]=temp;
                return s;
            }
        }else{
            return s;
        }
    }

    if(isSmaller(s,p))
        return s;
    else
        return "---";
}

int main(){
    int t;
    string s,p;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s>>p;
        cout<<strictSmall(s,p)<<"\n";
    }
    return 0;
}
