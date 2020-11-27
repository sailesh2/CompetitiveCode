class Solution {
private:
    vector<int> a;
    int n,dist;
    int dp[1001];
    void clearDP(){
        for(int i=0;i<=1000;i++)
            dp[i]=-1;
    }

    int maxJumps(int pos){
        int maxi=0;
        for(int i=pos+1;i<=pos+dist && i<n;i++){
            if(a[i]>=a[pos])
                break;
            if(dp[i]==-1)
                maxi=max(maxi,maxJumps(i));
            else
                maxi=max(maxi,dp[i]);
        }

        for(int i=pos-1;i>=pos-dist && i>=0;i--){
            if(a[i]>=a[pos])
                break;
            if(dp[i]==-1)
                maxi=max(maxi,maxJumps(i));
            else
                maxi=max(maxi,dp[i]);
        }
        dp[pos]=maxi+1;
        return maxi+1;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        dist=d;
        a=arr;
        int maxi=0;
        clearDP();
        for(int i=0;i<n;i++){

            if(dp[i]==-1){
                maxi=max(maxi,maxJumps(i));
            }else{
                maxi=max(maxi,dp[i]);
            }
        }

        return maxi;
    }
};
