#include<bits/stdc++.h>

using namespace std;
   bool fun(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }

class Solution {
private:

public:


    int findLongestChain(vector<vector<int> >& pairs) {
        int maxi,gmax=0,longest[1001]={0};
        sort(pairs.begin(),pairs.end(),fun);
        for(int i=pairs.size()-1;i>=0;i--){
            maxi=0;
            for(int j=i+1;j<pairs.size();j++){
                if(pairs[i][1]<pairs[j][0]){
                    maxi=max(maxi,longest[j]);
                }
            }
            longest[i]=maxi+1;
            gmax=max(gmax,longest[i]);
        }
        return gmax;
    }
};
