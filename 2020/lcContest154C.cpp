class Solution {
private:
    long long int prefixSum(vector<int>& arr){
        long long int s=0;
        long long int maxi=0;
        for(int i=0;i<arr.size();i++){
            s=s+arr[i];
            maxi=max(maxi,s);

        }
        return maxi;
    }

    long long int suffixSum(vector<int>& arr){
        long long int s=0;
        long long int maxi=0;
        for(int i=arr.size()-1;i>=0;i--){
            s=s+arr[i];
            maxi=max(maxi,s);

        }
        return maxi;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int sm=0,sm2=0;
        long long int mod=1000000007;

        for(int i=0;i<arr.size();i++){
            sm=sm+arr[i];
        }
        if(sm>0){
            sm2=sm;
            sm=(sm*k)%mod;
        }
        long long int maxi=sm;
        long long int subsum=0;
        for(int i=0;i<arr.size();i++){
            subsum=subsum+arr[i];
            maxi=max(maxi,subsum);
            if(subsum<0){
                subsum=0;
            }
        }
        if(k>1){

            long long int pre=prefixSum(arr);
            long long int suf=suffixSum(arr);
            long long int pre2=pre,suf2=suf;
            long long int csum=(pre+suf)%mod;
            maxi=max(maxi,csum);

            for(int i=0;i<arr.size();i++){
                suf=suf+arr[i];
                maxi=max(maxi,suf);
                if(suf<0)
                    break;
            }
            for(int i=arr.size()-1;i>=0;i--){
                pre=pre+arr[i];
                maxi=max(maxi,pre);
                if(pre<0)
                    break;
            }

            if(sm>0){
                maxi=max(maxi,((sm2*(k-1))%mod + pre2)%mod);
                maxi=max(maxi,((sm2*(k-1))%mod + suf2)%mod);
                cout<<pre2<<" "<<suf2<<" "<<sm2;
                if(k-2>=0)
                maxi=max(maxi,((sm2*(k-2))%mod + (pre2 + suf2)%mod)%mod);
            }
        }
        return maxi%mod;
    }
};
