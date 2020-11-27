class Solution {
private:
    int dp[100005];
    int n;
    vector<int> bridge;
    map<int,vector<int>> nbh;
    map<int,vector<int>>::iterator nbhIt;

    void setup(){
        for(int i=0;i<=n;i++)
            dp[i]=-1;

        for(int i=0;i<n;i++){
            int val=bridge[i];

            nbhIt = nbh.find(val);
            vector<int> v;
            if(nbhIt!=nbh.end()){
                v=nbhIt->second;
                nbh.erase(nbhIt);
            }

            v.push_back(i);
            nbh.insert(make_pair(val,v));
        }
    }

    int minJumps(int index, int* has){
        if(index==n-1)
            return 0;

        int mini=1000000007;

        if(has[index+1]==0){
            has[index+1]=1;
                mini=dp[index+1]==-1?minJumps(index+1,has)+1:dp[index+1]+1;
            has[index+1]=0;
        }

        if(index-1>=0){
            if(has[index-1]==0){
                has[index-1]=1;
                mini=min(mini, (dp[index-1]==-1?minJumps(index-1,has)+1:dp[index-1]+1));
                has[index-1]=0;
            }
        }

        nbhIt=nbh.find(bridge[index]);
        vector<int> v=nbhIt->second;
        for(int i=0;i<v.size();i++){
            if(v[i]!=index){
                if(has[v[i]]==0){
                    has[v[i]]=1;
                    mini=min(mini, (dp[v[i]]==-1?minJumps(v[i],has)+1:dp[v[i]]+1));
                    has[v[i]]=0;
                }
            }
        }

        dp[index]=mini;
        return mini;
    }

public:
    int minJumps(vector<int>& arr) {
        n=arr.size();
        bridge=arr;
        setup();
        int has[100005]={0};
        has[0]=1;
        return minJumps(0,has);
    }
};
