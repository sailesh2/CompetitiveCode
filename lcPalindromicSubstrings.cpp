#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int left,right,ctr,a=0;
        for(int i=0;i<s.length();i++){
            left=i-1;
            right=i+1;
            ctr=0;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
                ctr++;
            }
            a=a+ctr;
            left=i-1;
            right=i+2;
            ctr=0;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                left--;
                right++;
                ctr++;
            }
            a=a+ctr;
        }
        return a;
    }
};
