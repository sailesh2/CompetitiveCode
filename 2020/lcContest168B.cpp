class Solution {
public:
bool isPossibleDivide(vector<int>& nums, int k) {
      	map<int,int> has;
		map<int,int>::iterator hasIt;

sort(nums.begin(),nums.end());
for(int i=0;i<nums.size();i++){
	hasIt=has.find(nums[i]);
	int c=0;
	if(hasIt!=has.end()){
		c=hasIt->second;
		has.erase(hasIt);
}
has.insert(make_pair(nums[i],c+1));
}


for(int i=0;i<nums.size();i++){
	hasIt=has.find(nums[i]);
	int c = hasIt->second;
	if(c>0){
		has.erase(hasIt);
		has.insert(make_pair(nums[i],c-1));
		for(int j=1;j<k;j++){
			hasIt=has.find(nums[i]+j);
			c=hasIt->second;
			if(c==0)
				return false;
			has.erase(hasIt);
			has.insert(make_pair(nums[i]+j,c-1));
}
}
}

return true;
    	}
};
