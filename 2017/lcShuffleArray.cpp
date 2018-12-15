#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    vector<int> original;
public:
    Solution(vector<int> nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffled=original;
        vector<int> shuffle=original;
        int c;
        for(int i=0;i<original.size();i++){
            c=rand()%(original.size()-i);
            shuffled[i]=shuffle[c];
            shuffle.erase(shuffle.begin()+c);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
