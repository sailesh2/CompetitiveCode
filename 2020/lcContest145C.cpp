class Solution {
private:
    int longest(vector<int> hours){
        int dp[17][10005]={0};

        for(int i=0;i<hours.size();i++){
            if(i>0){
            for(int j=0;j<=16;j++){
                dp[j][i]=dp[j][i-1];
            }
            }
            dp[hours[i]][i]++;
        }


        int start=0;
        int end=-1;
        for(int i=hours.size()-1;i>=0;i--){
            int c=0;
            for(int j=0;j<=8;j++){
                if(start-1>=0)
                c=c-(dp[j][i] - dp[j][start-1]);
                else
                c=c-dp[j][i];
            }
            for(int j=9;j<=16;j++){
                if(start-1>=0)
                c=c+dp[j][i] - dp[j][start-1];
                else
                c=c+dp[j][i];
            }
            if(c>0){
                end=i;
                break;
            }
        }
        int maxi=end-start+1;

        while(start<hours.size()){
            if(hours[start]>8)
            break;
            start++;
            if(start>end)
                end=start;
            for(int i=end;i<hours.size();i++){

                int c=0;
                for(int j=0;j<=8;j++){
                    if(start-1>=0)
                    c=c-(dp[j][i] - dp[j][start-1]);
                    else
                    c=c-dp[j][i];
                }
                for(int j=9;j<=16;j++){
                    if(start-1>=0)
                    c=c+dp[j][i] - dp[j][start-1];
                    else
                    c=c+dp[j][i];
                }
                if(c>0){
                end=i;
                maxi=max(maxi,end-start+1);
                }

            }
        }
        return maxi;
    }

    vector<int> rev(vector<int> inp){
        vector<int> revs;
        for(int i=inp.size()-1;i>=0;i--)
            revs.push_back(inp[i]);
        return revs;
    }

public:
    int longestWPI(vector<int>& hours) {
        return max(longest(hours),longest(rev(hours)));

    }
};
