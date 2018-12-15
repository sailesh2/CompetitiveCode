#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> rev,digs;
        while(N>0){
            rev.push_back(N%10);
            N=N/10;
        }
        for(int i=rev.size()-1;i>=0;i--){
            digs.push_back(rev[i]);
        }
        int save;
        while(1){
            save=-1;
            for(int i=1;i<digs.size();i++){
                if(digs[i]<digs[i-1]){
                    save=i;
                    break;
                }
            }
            if(save==-1)
                break;
            digs[save-1]--;
            for(int i=save;i<digs.size();i++){
                digs[i]=9;
            }
        }
        int num=0;
        for(int i=0;i<digs.size();i++){
            num=num*10+digs[i];
        }
        return num;
    }
};
