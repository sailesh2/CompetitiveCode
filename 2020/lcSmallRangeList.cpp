class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        set<pair<int,int>> st;
        set<pair<int,int>>::iterator stIt;
        int index[k];
        for(int i=0;i<k;i++){
            index[i]=0;
            st.insert(make_pair(nums[i][0],i));
        }

        stIt = st.begin();
        int mini = stIt->first;

        stIt = st.end();
        stIt--;
        int maxi = stIt->first;

        int minAns = maxi-mini;
        int savea = mini;
        int saveb = maxi;

        while(1){
            stIt = st.begin();
            int ind = stIt->second;
            index[ind]++;
            if(index[ind]==nums[ind].size()){
                break;
            }
            st.erase(stIt);
            st.insert(make_pair(nums[ind][index[ind]],ind));

            stIt = st.begin();
            mini = stIt->first;

            stIt = st.end();
            stIt--;
            maxi = stIt->first;

            if( maxi-mini < minAns){
                minAns = maxi - mini;
                savea=mini;
                saveb=maxi;
            }

        }

        vector<int> v;
        v.push_back(savea);
        v.push_back(saveb);

        return v;
    }
};
