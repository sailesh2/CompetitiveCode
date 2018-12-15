#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
int total,ans=0;
vector<int> factors[16];
void beautiful(int ind,int *has){
    if(ind==total){
        int cnt=0;
        for(int i=0;i<factors[ind].size();i++){
            if(has[factors[ind][i]]==0){
                if(factors[ind][i]%ind==0 || ind%factors[ind][i]==0){
                    cnt=1;
                    break;
                }
            }
        }
        if(cnt==1)
        ans++;
        return;
    }
    for(int i=0;i<factors[ind].size();i++){
        if(has[factors[ind][i]]==0){
            has[factors[ind][i]]=1;
            beautiful(ind+1,has);
            has[factors[ind][i]]=0;
        }
    }
}
public:
    int countArrangement(int N) {
        total=N;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i%j==0 || j%i==0){
                    factors[i].push_back(j);
                }
            }
        }
        int has[16]={0};
        beautiful(1,has);
        return ans;
    }
};

int main(){
    Solution sol;
    cout<<sol.countArrangement(4);
    return 0;
}


