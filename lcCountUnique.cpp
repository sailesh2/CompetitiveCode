class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int sm=10,j=9,p=9;
        for(int i=1;i<n;i++){
            p=p*j;
            j--;
            sm=sm+p;
        }
        return sm;
    }
};
