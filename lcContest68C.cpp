class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ctr=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            ctr++;
            for(int j=i+1;j<=maxi;j++){
                maxi=max(maxi,arr[j]);
            }
            i=maxi;
        }
        return ctr;
    }
};
