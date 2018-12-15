#include<bits/stdc++.h>

using namespace std;
set<long long int> squares;
int mini;
void hasSquares(){
    long long int p;
    for(int i=1;i<=100000;i++){
        p=(long long int)i*i;
        squares.insert(p);
    }
}

string convertToStr(int n){
    string s="",rev="";
    while(n>0){
        rev=rev+(char)(n%10+48);
        n=n/10;
    }
    for(int i=rev.length()-1;i>=0;i--){
        s=s+rev[i];
    }
    return s;
}

void findMinSteps(int ind,long long int formed,string s,int ctr,int taken){
    if(ind==s.length()){
        if(squares.count(formed)>0){
            mini=min(mini,ctr);
        }
        return;
    }
    findMinSteps(ind+1,formed,s,ctr+1,taken);
    if(s[ind]=='0'){
        if(taken>0)
            findMinSteps(ind+1,formed*10+(int)s[ind]-48,s,ctr,taken+1);
    }else{
        findMinSteps(ind+1,formed*10+(int)s[ind]-48,s,ctr,taken+1);
    }
}
int main(){
    int n;
    cin>>n;
    string s = convertToStr(n);
    mini=s.length()+1;
    hasSquares();
    findMinSteps(0,0,s,0,0);
    if(mini==s.length()+1){
        mini=-1;
    }
    cout<<mini;
    return 0;
}
