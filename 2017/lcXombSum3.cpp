class Solution {
private:
    vector<vector<int> > ans;
    vector<int> v;
    set<long long int> has;
    int taken[10]={0};
    void backTrack(int n,int k){
        if(k==0 && n==0){
            long long int p=1;
            for(int i=0;i<v.size();i++){
                p=p*v[i];
            }
            if(has.count(p)==0){
                ans.push_back(v);
                has.insert(p);
            }
            return;
        }

        if(k<=0 || n<=0)
            return;
        for(int i=1;i<=9;i++){
            if(taken[i]==0){
                taken[i]=1;
                v.push_back(i);
                backTrack(n-i,k-1);
                v.pop_back();
                taken[i]=0;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(n,k);
        return ans;
    }
};
