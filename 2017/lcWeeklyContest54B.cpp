#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt,ctr=0,sm=0,l1=0,l2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(cnt==1){
                    ctr++;
                }
                cnt=0;
            }
            if(s[i]=='1'){
                if(cnt==0){
                    ctr++;
                }
                cnt=1;
            }
            if(ctr==1){
                l2++;
            }else if(ctr==0){
                l1++;
            }
            if(ctr==2){
                sm=sm+min(l1,l2);
                ctr=1;
                l1=l2;
                l2=1;
            }
        }
        sm=sm+min(l1,l2);
        return sm;
    }
};

int main(){
    Solution sol;
    cout<<sol.countBinarySubstrings("00110011");
    return 0;
}
