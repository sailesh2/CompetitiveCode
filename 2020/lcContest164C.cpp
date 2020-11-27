class Solution {
private:
    int dp[50]={0};
    int preSm[50]={0};

    void clearDP(){
        for(int i=0;i<50;i++)
            dp[i]=-1;
    }

    void prefixStoreSum(vector<int>& arr){
        int s=0;
        for(int i=0;i<arr.size();i++){
            s=max(s,arr[i]);
            preSm[i]=s;
        }
    }

    void setup(vector<int>& arr){
        clearDP();
        prefixStoreSum(arr);
    }

    int minTreeSum(int endIndex,vector<int>& arr){
        if(endIndex==0)
            return arr[0];
        if(endIndex==1)
            return arr[0]*arr[i];
        int sm;
        if(dp[endIndex-1]!=-1)
            sm=dp[endIndex-1];
        else
            sm=minTreeSum(endIndex-1,arr);
        int p1=preSm(endIndex-1)*arr[endIndex] + sm;

        if(dp[endIndex-2]!=-1)
            sm=dp[endIndex-2];
        else
            sm=minTreeSum(endIndex-2,arr);

        int p2=preSm(endIndex-2)*(max(arr[endIndex],arr[endIndex-1])) + sm;
        dp[endIndex]=min(p1,p2);
        return min(p1,p2);
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        setup(arr);
        return minTreeSum(arr.size()-1,arr);
    }
};
