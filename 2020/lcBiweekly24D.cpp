class Solution {
private:
    int dp[100005];
    int mod=1000000007;
    long long int maxi;
    int n;
    string str;

    void clearDP(){
        for(int i=0;i<=n;i++)
            dp[i]=-1;
    }

    long long int getNum(int start, int end){
        long long int num=0;
        for(int i=start;i<=end;i++)
            num=num*10+(long long int)(str[i]-'0');
        return num;
    }

    int ways(int index){
        if(index==n)
            return 1;
        if(str[index]=='0')
            return 0;

        int c=0;
        for(int i=index;i<min(n,index+10);i++){
            long long int segNum = getNum(index,i);
            if(segNum<=maxi){
                if(dp[i+1]==-1)
                    c=(c+ways(i+1))%mod;
                else
                    c=(c+dp[i+1])%mod;
            }
        }
        dp[index]=c;
        return c;
    }

public:
    int numberOfArrays(string s, int k) {
        n=s.length();
        str=s;
        maxi=k;
        clearDP();
        return ways(0);
    }
};
