class Solution {
private:
    vector<int> sl;


    int maxSlices(){
        int sz=sl.size();
        if(sz==2)
            return max(sl[0],max(sl[1],sl[2]));
        int dp[505],dp1[505],dp2[505];
        int v=0;
        for(int i=0;i<sl.size();i++){
            dp1[i]=max(v,sl[i]);
        }
        v=0;
        for(int i=sl.size()-1;i>=0;i--){
            dp2[i]=max(v,sl[i]);
        }
        v=0;
        for(int i=0;i<sl.size();i++){
            if(i<=1)
                dp[i]=sl[i]+dp2[i+2];
            else if(i>=sl.size()-2)
                dp[i]=sl[i]+dp[i-2];
            else
                dp[i]=sl[i]+dp1[i-2]+dp2[i+2];
            v=max(v,dp[i]);
        }
        return v;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        sl=slices;
        return maxSlices();
    }
};
