#include<bits/stdc++.h>

using namespace std;

int dp[401][401][401];

void clearDP(int l, int m){
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l;j++){
            for(int k=0;k<=m;k++){
                dp[i][j][k]=-1;
            }
        }
    }
}

int firstLen, secondLen;
string s,p;

bool isPossible(int firstIndex, int secondIndex, int index){

    if(firstIndex>=firstLen && secondIndex>=secondLen)
        return true;

    if(index==s.length())
        return false;

    bool v=false;

    int dpIt1 = dp[firstIndex+1][secondIndex][index+1];
    int dpIt2 = dp[firstIndex][secondIndex+1][index+1];
    int dpIt3 = dp[firstIndex][secondIndex][index+1];

    if(firstIndex<firstLen && p[firstIndex] == s[index] && secondIndex<secondLen && p[secondIndex] == s[index]){
        bool v1 = false;
        bool v2 = false;

        if(dpIt1 == -1 && dpIt2 == -1){


            v1=isPossible(firstIndex+1, secondIndex, index+1);
            if(!v1){
                v2=isPossible(firstIndex, secondIndex+1, index+1);
            }
        }else if(dpIt1 == -1){
            v2=dpIt2 == 0;
            if(!v2){
                v1=isPossible(firstIndex+1, secondIndex, index+1);
            }
        }else if(dpIt2 == -1){
            v1=dpIt1 == 0;
            if(!v1){
                v2=isPossible(firstIndex, secondIndex+1, index+1);
            }
        }else{
            v1=dpIt1 == 0;
            v2=dpIt2 == 0;
        }

        v=v1 || v2;
    }else if(firstIndex<firstLen && p[firstIndex] == s[index]){
        if(dpIt1 == -1)
            v=isPossible(firstIndex+1, secondIndex, index+1);
        else
            v=dpIt1 == 0;
    }else if(secondIndex<secondLen &&p[secondIndex] == s[index]){
        if(dpIt2 == -1)
            v=isPossible(firstIndex, secondIndex+1, index+1);
        else
            v=dpIt2 == 0;
    }else{
        if(dpIt3 == -1)
            v=isPossible(firstIndex, secondIndex, index+1);
        else
            v=dpIt3 == 0;
    }

    dp[firstIndex][secondIndex][index] = v?0:1;
    return v;
}

string isPossible(){
    bool pos=false;
    int m=s.length();
    int l=p.length();

    secondLen=l;
    for(int i=0;i<l;i++){
        firstLen=i;
        if(isPossible(0,i,0)){
            pos=true;
            break;
        }
    }

    return pos?"YES":"NO";
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s>>p;
        clearDP(p.length(),s.length());
        cout<<isPossible()<<"\n";
    }
    return 0;
}
