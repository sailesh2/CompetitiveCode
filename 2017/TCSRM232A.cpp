#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;
class BritishCoins{
	public:
	vector<int> coins(int p){
		int pounds=p/120;
		int rem=p%120;
		int shillings = rem/12;
		rem=rem%12;
		vector<int> change;
		change.push_back(pounds);
		change.push_back(shillings);
		change.push_back(rem);
		return change;
	}
};

int main(){
return 0;
}
