#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cnt=0;
        for(int i=0;i<bits.size();i++){
            if(bits[i]==1){
                cnt=1;
                i++;
            }else{
                cnt=0;
            }
        }
        return cnt==0;
    }
};
