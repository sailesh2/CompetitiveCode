class Solution {
private:
    bool isCover(vector<int> a , vector<int> b){
        return a[0]>=b[0] && a[1]<=b[1];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int c=0;
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals.size();j++){
                if(i!=j){
                    if(isCover(intervals[i], intervals[j])){
                        c++;
                        break;
                    }
                }
            }
        }

        int ans = intervals.size();
        ans=ans-c;
        return ans;
    }
};
