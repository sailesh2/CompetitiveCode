class Solution {
private:
    int getProd(int n){
        int p=1;
        while(n>0){
            p=p*(n%10);
            n=n/10;
        }
        return p;
    }
    int getSum(int n){
        int p=0;
        while(n>0){
            p=p+(n%10);
            n=n/10;
        }
        return p;
    }
public:
    int subtractProductAndSum(int n) {
        return getProd(n) - getSum(n);
    }
};
