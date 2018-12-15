
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        set<int> st;
        set<int>::iterator stIt;
        ans.push_back(1);
        st.insert(1);
        int i,ctr=1,cnt=0,l=k;
        while(l>=1){

            i=ans[ans.size()-1];

            if(cnt==0){
            ans.push_back(i+l);
            st.insert(i+l);
            }

            if(cnt==1){
            ans.push_back(i-l);
            st.insert(i-l);
            }

            cnt=1-cnt;
            l--;
            ctr++;
        }
        while(ctr<n){

            i=ans[ans.size()-1];
            for(int j=1;j<=k;j++){
                if(i+j<=n && st.count(i+j)==0){
                    ans.push_back(i+j);
                    st.insert(i+j);
                    break;
                }
                else if(i-j>=1 && st.count(i-j)==0){
                    ans.push_back(i-j);
                    st.insert(i-j);
                    break;
                }
            }
            ctr++;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    sol.constructArray(3,2);
    return 0;
}
