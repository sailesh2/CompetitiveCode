class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ctr=0;

        for(int i=0;i<arr.size()-1;i++){
            int s=arr[i];
            for(int j=i+1;j<arr.size();j++){
                s=s^arr[j];
                if(s==0)
                    ctr = ctr + (j-i);
            }
        }
        return ctr;
    }
};
