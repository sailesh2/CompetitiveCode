class Solution {
private:
    map<int,vector<int> > mp;
    map<int,vector<int> >::iterator mpIt;
    vector<int> v;
public:
    Solution(vector<int> nums) {
        int i;
        for(i=0;i<nums.size();i++){
            mpIt=mp.find(nums[i]);
            v.clear();
            if(mpIt!=mp.end()){
                v=mpIt->second;
                mp.erase(mpIt);
            }
            v.push_back(i);
            mp.insert(make_pair(nums[i],v));
        }

    }

    int pick(int target) {
        v = (mp.find(target))->second;
        int randomIndex=random()%(v.size());
        return v[randomIndex];
    }
};

class Solution {
private:
    vector<int> orig;
    vector<int> v;
public:
    Solution(vector<int> nums) {
        orig=nums;
    }

    int pick(int target) {
        v.clear();
        for(int i=0;i<orig.size();i++){
            if(orig[i]==target){
                v.push_back(i);
            }
        }
        return v[random()%v.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */


/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
