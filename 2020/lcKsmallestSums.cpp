class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int,int>> ans;
        if(nums1.size() == 0 || nums2.size() == 0){
            return ans;
        }
        set<pair<int,int>> heap;
        map<int,int> has;
        map<int,int>::iterator hasIt;
        heap.insert(make_pair(nums1[0]+nums2[0],0));
        has.insert(make_pair(0,0));
        int maxIndex=0;
        int cnt=0,tmp;
        int prod = nums1.size()*nums2.size();
        k=min(k,prod);
        while(cnt<k){
            int ind = (heap.begin())->second;
            heap.erase(heap.begin());
            ans.push_back(make_pair(nums1[ind],nums2[(has.find(ind))->second]));
            hasIt = has.find(ind);
            tmp=hasIt->second;
            tmp++;
            has.erase(hasIt);
            if(tmp<nums2.size()){
                has.insert(make_pair(ind,tmp));
                heap.insert(make_pair(nums1[ind]+nums2[tmp],ind));
            }
            if(ind == maxIndex){
                if(maxIndex+1 < nums1.size()){
                    maxIndex++;
                    has.insert(make_pair(maxIndex,0));
                    heap.insert(make_pair(nums1[maxIndex]+nums2[0],maxIndex));
                }
            }
            cnt++;
        }
        return ans;
    }
};
