#include<bits/stdc++.h>

using namespace std;
int has[10];

void preCompute(string s){
    int n = s.length();
    for(int i=0;i<10;i++)
        has[i]=0;
    for(int i=0;i<n;i++)
        has[s[i]-'0']++;
}

pair<string, int> prune(char fir, char sec, string s){
    string p="";
    int d=0;
    int n = s.length();
    int ctr=0;
    for(int i=0;i<n;i++){
        if(s[i]!=fir && s[i]!=sec)
            ctr++;
        else
            p.push_back(s[i]);
    }

    return make_pair(p,ctr);
}

int calDel(char fir, char sec, string s){
    int n = s.length();
    int d=0;
    string finS="";
    int ctr=0;

    for(int i=0;i<n;i++){
        if(ctr==0){
            if(s[i]==fir){
                finS.push_back(s[i]);
                ctr=1;
            }
            else
                d++;
        }else{
            if(s[i]==sec){
                finS.push_back(s[i]);
                ctr=0;
            }
            else
                d++;
        }
    }

    int fn = finS.length();
    if(fn%2==0)
        return d;
    else
        return fir==sec?d:min(d+1,n);
}

int cal(int fir, int sec, string s){

    pair<string, int> deleteInfo = prune((char)(48+fir),(char)(48+sec),s);

    string p = deleteInfo.first;
    int d = deleteInfo.second;

    if(fir==sec)
        return d;
    else
        return d+min(calDel((char)(48+fir),(char)(48+sec),p),calDel((char)(48+sec),(char)(48+fir),p));
}

int minDeletes(string s){
    int mini = s.length();
    //preCompute(s);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            mini=min(mini,cal(i,j,s));
        }
    }

    return mini;
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<minDeletes(s)<<"\n";
    }
    return 0;
}
