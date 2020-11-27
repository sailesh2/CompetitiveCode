class Solution {
private:
	int countDig(int x){
		int ctr=0;
		while(x>0){
			ctr++;
			x=x/10;
}
return ctr;
}
public:
int findNumbers(vector<int>& nums) {
      	int ctr=0;
for(int i=0;i<nums.size();i++){
	if(countDig(nums[i])%2==0)
		ctr++;
}
return ctr;
    	}
};
