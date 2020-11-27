#include<bits/stdc++.h>

using namespace std;

char getThirdChar(char a, char b){
    if(a=='S' && b=='T'){
        return 'E';
    }
    if(a=='T' && b=='S'){
        return 'E';
    }
    if(a=='S' && b=='E'){
        return 'T';
    }
    if(a=='E' && b=='S'){
        return 'T';
    }
    if(a=='E' && b=='T'){
        return 'S';
    }
    if(a=='T' && b=='E'){
        return 'S';
    }

}

pair<bool,string> getThird(string a, string b){
    string s="";
    bool cnt=false;
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i])
            s.push_back(a[i]);
        else{
            cnt=true;
            s.push_back(getThirdChar(a[i],b[i]));
        }

    }
    return make_pair(cnt,s);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<string> v;
    string s;
    int c;
    map<string,int> mp;
    map<string,int>::iterator mpIt;
    for(int i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
        mpIt=mp.find(s);
        c=0;
        if(mpIt!=mp.end()){
            c=mpIt->second;
            mp.erase(mpIt);
        }
        c++;
        mp.insert(make_pair(s,c));
    }
    int sm=0;
    for(int i=n-2;i>=0;i--){
        map<string,int> mp2;
        map<string,int>::iterator mp2It;
        for(int j=n-1;j>i;j--){
                pair<bool,string>p=getThird(v[i],v[j]);
                if(p.first){
                    s=p.second;
                    mp2It=mp2.find(s);
                    if(mp2It!=mp2.end()){
                        sm=sm+mp2It->second;
                    }
                }
                c=0;
                mp2It=mp2.find(v[j]);
                if(mp2It!=mp2.end()){
                    c=mp2It->second;
                    mp2.erase(mp2It);
                }
                c++;
                mp2.insert(make_pair(v[j],c));


        }
        mpIt=mp.find(v[i]);
        if(mpIt!=mp.end()){
            c=mpIt->second;
            sm=sm+(c*(c-1)*(c-2))/6;
        }
    }
    cout<<sm;
    return 0;
}
