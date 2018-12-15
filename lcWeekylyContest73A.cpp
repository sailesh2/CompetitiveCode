#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isNumberGood(int n){
        int cnt=0,a;
        while(n>0){
            a=n%10;
            if(a==3 || a==4 || a==7){
                cnt=0;
                break;
            }
            if(a==2 || a==5 || a==6 || a==9){
                cnt=1;
            }
            n=n/10;
        }
        return cnt==1;
    }
public:
    int rotatedDigits(int N) {
        int ctr=0;
        for(int i=1;i<=N;i++){
            if(isNumberGood(i))
                ctr++;
        }
        return ctr;
    }
};
