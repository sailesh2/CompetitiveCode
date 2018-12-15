#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size(),cnt=0;
        long long int profit=0;
        if(n<2){
            return 0;
        }
        int maxi=arr[n-1],mini=100000000;
        for(int i=n-2;i>=0;i--){
            if(cnt==0){
                if(arr[i]<arr[i+1]){
                    cnt=1;
                    mini=min(mini,arr[i]);
                }else{
                    maxi=max(maxi,arr[i]);
                }
            }else{
                if(arr[i]+fee>arr[i+1]){

                    cnt=0;
                    profit=profit+max(maxi-mini-fee,0);
                    maxi=arr[i];
                    mini=100000000;

                }else{
                     mini=min(mini,arr[i]);
                }
            }
        }
        return profit;
    }
};

int main(){
    return 0;
}
