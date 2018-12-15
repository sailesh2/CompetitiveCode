#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int l=temperatures.size();
        int stk[l];
        int top=-1;
        int ans[l],v;
        for(int i=l-1;i>=0;i--){
            v=temperatures[i];
            while(top>=0 && v>=temperatures[stk[top]]){
                top--;
            }
            if(top>=0){
                ans[i]=stk[top]-i;
            }else{
                ans[i]=0;
            }
            stk[++top]=i;
        }
        vector<int> ans2;
        for(int i=0;i<l;i++){
            ans2.push_back(ans[i]);
        }
        return ans2;
    }
};
