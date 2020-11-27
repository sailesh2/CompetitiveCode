class Solution {
private:
	bool canReach(vector<int>& arr, int start, int* has){
		if(arr[start]==0)
			return true;

if(start-arr[start]>=0 && has[start-arr[start]]==0){
	has[start-arr[start]]=1;
	if(canReach(arr, start-arr[start], has))
		return true;
}

if(start+arr[start]<arr.size() && has[start+arr[start]]==0){
	has[start+arr[start]]=1;
	if(canReach(arr, start+arr[start], has))
		return true;
}

return false;
}

public:
    bool canReach(vector<int>& arr, int start) {
    	  int has[50004]={0};
  has[start]=1;
  return canReach(arr,start,has);
    }
};
