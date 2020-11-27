#include<bits/stdc++.h>

using namespace std;
long long int p5=11881376;
long long int p4=456976;
long long int twone=9079022;
string s;
bool notLiked(int p1,int p2,int p3){
    return (s[p1]=='o' && s[p2]=='n' && s[p3]=='e') || (s[p1]=='t' && s[p2]=='w' && s[p3]=='o');
}

vector<int> minLastRemovals(){

    int l=s.length();
    int p1=0,p2=1,p3=2;
    vector<int> v;
    while(p3<l){
        if(notLiked(p1,p2,p3)){
            v.push_back(p2);
            p1=p3+1;
            p2=p1+1;
            p3=p2+1;
        }else{
            p1=p2;
            p2=p3;
            p3++;
        }
    }
    return v;
}


vector<int> removeCommon(){
    int l=s.length();
    vector<int> v;
    long long int t=0;
    for(int i=0;i<l;i++){
        if(i<5){
            t=t*26+(s[i]-'a');
        }else{
            t=t-(p4*(s[i-5]-'a'));
            t=t*26+(s[i]-'a');
        }
        if(t==twone){
            v.push_back(i-2);
        }
    }
    for(int i=0;i<v.size();i++)
        s[v[i]]='x';
    return v;
}

vector<int> minRemovals(){
    vector<int> v=removeCommon();
    vector<int> ans=minLastRemovals();

    for(int i=0;i<v.size();i++)
        ans.push_back(v[i]);
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        vector<int> v = minRemovals();
        cout<<v.size()<<"\n";
        for(int j=0;j<v.size();j++){
            cout<<v[j]+1<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
