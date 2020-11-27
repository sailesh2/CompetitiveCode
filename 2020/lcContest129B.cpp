class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int noOfOnes=0;
        int rem=0;
        int cnt;
        while(1){
            cnt=0;
            for(int i=0;i<10;i++){
                if((K*i+rem)%10==1){
                    noOfOnes++;
                    rem=(K*i+rem)/10;
                    cnt=1;
                    break;
                }
            }
            if(cnt==0 || rem==0)
                break;
        }
        return noOfOnes==0?-1:noOfOnes;
    }
};
