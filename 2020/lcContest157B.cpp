class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxi=0;
        map<int,int> mp;
        map<int,int>::iterator mpIt;
        for(int i=arr.size()-1;i>=0;i--){
            mpIt =mp.find(arr[i]+difference);
            int cnt=1;
            if(mpIt!=mp.end()){
                cnt = cnt+mpIt->second;
            }
            mpIt=mp.find(arr[i]);
            if(mpIt!=mp.end())
                mp.erase(mpIt);
            maxi=max(maxi,cnt);
            mp.insert(make_pair(arr[i],cnt));
        }

        return maxi;
    }
};
