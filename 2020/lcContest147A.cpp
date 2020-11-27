class Solution {
private:
    int fibDP[40]={0};

    int calTrib(int n){
        fibDP[0]=0;
        fibDP[1]=1;
        fibDP[2]=1;

        for(int i=3;i<=n;i++){
            fibDP[i]=fibDP[i-1]+fibDP[i-2]+fibDP[i-3];
        }

        return fibDP[n];
    }
public:
    int tribonacci(int n) {
        return calTrib(n);
    }
};
