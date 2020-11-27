class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        int maxi=0;
        int ctr=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,light[i]);
            if(maxi==i+1)
                ctr++;
        }
        return ctr;
    }
};
