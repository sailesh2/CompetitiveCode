#include<bits/stdc++.h>

using namespace std;

map<pair< pair<int,int>, int>, bool> dp;
map<pair< pair<int,int>, int>, bool>::iterator dpIt1,dpIt2,dpIt3;

int firstLen, secondLen;
string s,p;

bool isPossible(int firstIndex, int secondIndex, int index){

    if(firstIndex>=firstLen && secondIndex>=secondLen)
        return true;

    if(index==s.length())
        return false;

    bool v=false;

    dpIt1 = dp.find(make_pair(make_pair(firstIndex+1,secondIndex),index+1));
    dpIt2 = dp.find(make_pair(make_pair(firstIndex,secondIndex+1),index+1));
    dpIt3 = dp.find(make_pair(make_pair(firstIndex,secondIndex),index+1));

    if(firstIndex<firstLen && p[firstIndex] == s[index] && secondIndex<secondLen && p[secondIndex] == s[index]){
        bool v1 = false;
        bool v2 = false;

        if(dpIt1 == dp.end() && dpIt2 == dp.end()){


            v1=isPossible(firstIndex+1, secondIndex, index+1);
            if(!v1){
                v2=isPossible(firstIndex, secondIndex+1, index+1);
            }
        }else if(dpIt1 == dp.end()){
            v2=dpIt2->second;
            if(!v2){
                v1=isPossible(firstIndex+1, secondIndex, index+1);
            }
        }else if(dpIt2 == dp.end()){
            v1=dpIt1->second;
            if(!v1){
                v2=isPossible(firstIndex, secondIndex+1, index+1);
            }
        }else{
            v1=dpIt1->second;
            v2=dpIt2->second;
        }

        v=v1 || v2;
    }else if(firstIndex<firstLen && p[firstIndex] == s[index]){
        if(dpIt1 == dp.end())
            v=isPossible(firstIndex+1, secondIndex, index+1);
        else
            v=dpIt1->second;
    }else if(secondIndex<secondLen &&p[secondIndex] == s[index]){
        if(dpIt2 == dp.end())
            v=isPossible(firstIndex, secondIndex+1, index+1);
        else
            v=dpIt2->second;
    }else{
        if(dpIt3 == dp.end())
            v=isPossible(firstIndex, secondIndex, index+1);
        else
            v=dpIt3->second;
    }

    dp.insert(make_pair(make_pair(make_pair(firstIndex,secondIndex),index),v));
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
        dp.clear();
        cout<<isPossible()<<"\n";
    }
    return 0;
}
