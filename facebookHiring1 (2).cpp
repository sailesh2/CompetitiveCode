#include<bits/stdc++.h>
#define gc getchar

using namespace std;

inline int scan()
{
int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}


//DP used to store states of already calculated outcomes of a number.
map<int,int> dp;
map<int,int>::iterator dpIt;

vector<int> pows;

//Precalculates the powers of 2.
void precalculate(){
    int p=1;
    while(p<1000000000){
        pows.push_back(p);
        p=p*2;
    }
}

//Method to return number of ones in binary representation of n.
int countOne(int n){
    int ctr=0;
    while(n>0){
        ctr=ctr+n%2;
        n=n/2;
    }
    return ctr;
}

//Returns the status of game
int game(int n,int ones){

    //If other player lose in any one of the move of the current player, current player wins by choosing that move as
    //both player optimally. 0 for win and 1 for lose.

    int otherPlayerStatus=0;
    for(int k=0;k<pows.size();k++){
        if(pows[k]>=n){
            break;
        }
        if(countOne(n-pows[k])==ones){
            if(dpIt==dp.end()){
                otherPlayerStatus=game(n-pows[k],ones);
            }else{
                otherPlayerStatus=dpIt->second;
            }
            if(otherPlayerStatus==1)
                break;
        }
    }
    dp.insert(make_pair(n,1-otherPlayerStatus));
    return 1-otherPlayerStatus;
}
int main(){
    int n,t,ans;
    t=scan();
    precalculate();
    for(int i=0;i<t;i++){
        n=scan();
        dpIt=dp.find(n);
        if(dpIt!=dp.end()){
            ans=dpIt->second;
        }else{
            ans=game(n,countOne(n));
        }
        if(ans==0){
            cout<<"First Player\n";
        }else{
            cout<<"Second Player\n";
        }
    }
    return 0;
}
