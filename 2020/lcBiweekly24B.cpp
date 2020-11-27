class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long int fib[71];
        fib[0]=0;
        fib[1]=1;
        fib[2]=1;
        for(int i=3;i<71;i++){
            fib[i]=fib[i-1]+fib[i-2];
        }
        int ctr=0;
        for(int i=70;i>0;i--){
            if(fib[i]<=k){
                ctr++;
                k=k-fib[i];
            }
            if(k==0)
                break;
        }
        return ctr;
    }
};
