class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxiL=0;
        for(int i=0;i<left.size();i++)
            maxiL=max(maxiL,left[i]);
        for(int i=0;i<right.size();i++)
            maxiL=max(maxiL,n-right[i]);
        return maxiL;
    }
};
