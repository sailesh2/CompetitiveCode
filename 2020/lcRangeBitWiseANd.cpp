#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        vector<int> mBits;
        vector<int> nBits;
        vector<int> pows;
        int ctr=1;
        while(m>0){
            mBits.push_back(m%2);
            m=m/2;
            pows.push_back(ctr);
            ctr=ctr*2;
        }

        while(n>0){
            nBits.push_back(n%2);
            n=n/2;
        }

        if(mBits.size()!=nBits.size()){
            return 0;
        }else{
            int sm=0;
            for(int i=mBits.size()-1;i>=0;i--){
                if(mBits[i]==0 && nBits[i]==1){
                    break;
                }
                if(mBits[i]==1)
                sm=sm+pows[i];
            }
            return sm;
        }

    }
};
