#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        return binSear(citations);
    }

private:
    int binSear(vector<int> pc2){
        int ctr=1;
        int n = pc2.size();
        int save=0;
        int save2=0;

        while(1){
            while(save+ctr<=n && (save+ctr)<=pc2[n-(save+ctr)]){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save;
    }
};
int main(){
    return 0;
}
