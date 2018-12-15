class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ctr=0,save,maxi;
        for(int i=0;i<arr.size();i++){
            ctr++;
            save=i;
            maxi=arr[i];
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]<maxi){
                    save=j;
                }else {
                    maxi=arr[j];
                }
            }
            i=save;
        }
        return ctr;
    }
};
