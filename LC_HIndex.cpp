#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i=0,h=0,maxH=0,n=citations.size();
        while(i<n && h<=n){
            if(citations[i]>=h){
                if(n-i==h){
                    maxH=max(maxH,h);
                    i++;
                    h++;
                }else if(n-i>h){
                    if(citations[i]>=n-i){
                        h=n-i;
                    }else{
                        i++;
                    }
                }else{
                    i++;
                }
            }else{
                i++;
            }
        }
        return maxH;
    }
};
int main(){
    return 0;
}
