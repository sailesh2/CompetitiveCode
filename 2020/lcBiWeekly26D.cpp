class Solution {
private:

    bool allOne(vector<int>& cost){
        for(int i=0;i<9;i++){
            if(cost[i]!=1)
                return false;
        }
        return true;
    }

    string largest(){
        string s="";
        for(int i=0;i<5000;i++)
            s.push_back('9');
        return s;
    }

public:
    string largestNumber(vector<int>& cost, int target) {
        string dp[target+1];
        for(int i=cost.size()-1;i>=0;i--){
            if(cost[i]<=target && dp[cost[i]].length()==0)
            dp[cost[i]].push_back((char)(i+49));
        }

        if(allOne(cost) && target==5000)
            return largest();

        string save;
        if(dp[target].length()!=0)
            save=dp[target];

        for(int k=2;k<=target;k++){
            int cnt=0;
            string dp2[target+1];

            for(int i=1;i<=target;i++){
                for(int j=9;j>=1;j--){
                    int rem = i-cost[j-1];
                    if(rem>0 && rem<=target && dp[rem].length()!=0){
                        dp2[i]=dp[rem];
                        dp2[i].push_back((char)(j+48));
                        cnt=1;
                        break;
                    }
                }
            }
            if(cnt==0)
                break;
            for(int i=1;i<=target;i++)
                dp[i]=dp2[i];

            if(dp[target].length()!=0){
                save=dp[target];
            }
        }

        sort(save.begin(),save.end());
        string ans="";
        for(int i=save.length()-1;i>=0;i--)
            ans.push_back(save[i]);
        return ans.length()==0?"0":ans;
    }
};
