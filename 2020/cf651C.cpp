#include<bits/stdc++.h>

using namespace std;

string s1="Ashishgup";
string s2="FastestFinger";

string checkWinner(int n){
    if(n%2!=0){
        return n==1?s2:s1;
    }
    int ctr2=0;
    while(n%2==0){
        n=n/2;
        ctr2++;
    }

    int sumodd=0;
    int cnt=0;
    for(int i=3;i*i<=n;i=i+2){
        while(n%i==0){
            sumodd++;
            if(sumodd>1){
                cnt=1;
                break;
            }
            n=n/i;
        }
    }

    if(n>2 && cnt==0)
        sumodd++;

    if(ctr2>1){
        if(sumodd>0)
            return s1;
        else
            return s2;
    }else{

        if(sumodd==0)
            return s1;
        else if(sumodd==1)
            return s2;
        else
            return s1;
    }

    return s1;
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<checkWinner(n)<<"\n";
    }
    return 0;
}
