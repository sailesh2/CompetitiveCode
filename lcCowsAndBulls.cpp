#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string getHint(string secret, string guess) {
        int has[10]={0};
        int secHas[10]={0};
        int gueHas[10]={0};
        int bulls=0;
        int cows=0;
        for(int i=0;i<guess.length();i++){
            if(guess[i]==secret[i]){
                has[(int)(guess[i]-48)]++;
                bulls++;
            }
            secHas[(int)(secret[i]-48)]++;
            gueHas[(int)(guess[i]-48)]++;
        }
        for(int i=0;i<10;i++){
            cows=cows+min(secHas[i],gueHas[i])-has[i];
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
