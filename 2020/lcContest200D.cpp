class Solution {
private:
	long long int dp[200005][2];
	map<long long int,long long int> has1,has2;
	map<long long int,long long int>::iterator hasIt;
    long long int mod = 1000000007;

	void clearDP(long long int n){
		for(long long int i=0;i<=n+1;i++){
			dp[i][0]=-1;
			dp[i][1]=-1;
}
}

void createHash1(vector<long long int> nums){
	for(long long int i=0;i<nums.size();i++){
		has1.insert(make_pair(nums[i],i));
}
}


void createHash2(vector<long long int> nums){
	for(long long int i=0;i<nums.size();i++){
		has2.insert(make_pair(nums[i],i));
}
}

long long int calSum(long long int index, long long int row, vector<long long int>& nums1, vector<long long int>& nums2){
	if(dp[index][row-1]==-1)
		return maxSum(index,row,nums1,nums2);
	else
		return dp[index][row-1];
}

long long int maxSum(long long int index, long long int row, vector<long long int>& nums1, vector<long long int>& nums2){
	long long int hasInd;
    long long int v;

    if(row==1){
        if(index==nums1.size())
                return 0;
        hasIt = has2.find(nums1[index]);
        if(hasIt!=has2.end()){
            hasInd=hasIt->second;
            v = (nums1[index]+max(calSum(index+1,1,nums1,nums2),calSum(hasInd+1,2,nums1,nums2)))%mod;
        }else{
            v = (nums1[index]+calSum(index+1,1,nums1,nums2))%mod;
        }
    }else{
        if(index==nums2.size())
            return 0;
        hasIt = has1.find(nums2[index]);
        if(hasIt!=has1.end()){
            hasInd=hasIt->second;
            v= (nums2[index]+max(calSum(index+1,2,nums1,nums2), calSum(hasInd+1,1,nums1,nums2)))%mod;

        }else{
                v=( nums2[index]+calSum(index+1,2,nums1,nums2))%mod;

        }
    }

    dp[index][row-1]=v;
    return v;
}
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
      	createHash1(nums1);
        createHash2(nums2);
        long long int n = max(nums1.size(),nums2.size());
        clearDP(n);

        return max(maxSum(0,1,nums1,nums2),maxSum(0,2,nums1,nums2));
    }
};
