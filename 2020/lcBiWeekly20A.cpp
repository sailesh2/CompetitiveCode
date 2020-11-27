
int countBit(int x){
	int ctr=0;
	while(x>0){
		if(x%2==1)
			ctr++;
		x=x/2;
}
return ctr;
}

bool bitComp(int a, int b){
	int abit = countBit(a);
	int bbit = countBit(b);
	if(abit==bbit)
		return a<b;
	return abit<bbit;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),bitComp);
        return arr;
    }
};
