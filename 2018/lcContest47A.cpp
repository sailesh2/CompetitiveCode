class Solution {
private:
    int isPrime[100]={0};
    void countPrimes(){
        int cnt;
        isPrime[0]=0;
        isPrime[1]=0;
        for(int i=2;i<100;i++){
            cnt=0;
            for(int j=2;j<i;j++){
                if(i%j==0){
                    cnt=1;
                    break;
                }
            }
            isPrime[i]=1-cnt;
        }
    }
public:
    int countPrimeSetBits(int L, int R) {
        int ans=0;
        int ctr,val;
        countPrimes();
        for(int i=L;i<=R;i++){
            val=i;
            ctr=0;
            while(val>0){
                if(val%2==1)
                    ctr++;
                val=val/2;
            }
            if(isPrime[ctr]==1){
                ans++;
            }
        }
        return ans;
    }
};
