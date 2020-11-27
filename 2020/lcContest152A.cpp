class Solution {
private:

    long long int mod=1000000007;

    bool isPrime(int n){
        if(n==1)
            return false;
        for(int i=2;i<n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    long long int fac(int n){
        long long int ans=1;
        for(int i=1;i<=n;i++){
            ans=(ans*i)%mod;
        }
        return ans;
    }
public:
    int numPrimeArrangements(int n) {
        long long int ans=1;
        int ctr=0;
        for(int i=1;i<=n;i++){
            if(isPrime(i)){
                ctr++;
            }
        }

        ans= (fac(ctr)*fac(n-ctr))%mod;
        return ans;
    }
};
