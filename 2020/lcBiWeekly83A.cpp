class Solution {
private:
    int getDigSum(int n){
        int ctr=0;
        while(n>0){
            ctr=ctr+n%10;
            n=n/10;
        }
        return ctr;
    }
public:
    int countLargestGroup(int n) {
        int smArr[100005]={0};
        int maxi=0;
        for(int i=1;i<=n;i++){
            int digSum = getDigSum(i);
            maxi=max(maxi,digSum);
            smArr[digSum]++;
        }

        int maxDig=0;
        for(int i=0;i<=maxi;i++){
            maxDig=max(maxDig,smArr[i]);
        }
        int ctr=0;
        for(int i=0;i<=maxi;i++){
            if(maxDig==smArr[i])
                ctr++;
        }

        return ctr;
    }
};
