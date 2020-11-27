class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int s=0;
        int cnt=0;
        for(int i=0;i<k;i++){
            s=s+arr[i];
        }
        if((double)s/k>=threshold){
            cnt++;
        }

        for(int i=k;i<arr.size();i++){
            s=s-arr[i-k];
            s=s+arr[i];
            if((double)s/k>=threshold)
                cnt++;
        }

        return cnt;
    }
};
