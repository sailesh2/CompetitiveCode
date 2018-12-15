#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int sm[11]={0};
    void preprocessing(){
        sm[1]=0;
        sm[2]=1;
        for(int i=3;i<=10;i++){
            sm[i]=sm[i-1]+(i*(i-1))/2;
        }
    }
public:
    int findIntegers(int num) {
        vector<int> digs;
        int n=num;
        while(num>0){
            digs.push_back(num%2);
            num=num/2;
        }
        int sum=0,cnt=0;
        preprocessing();
        for(int i=digs.size()-1;i>=0;i--){
            if(digs[i]==1){
                sum=sum+sm[i];
                if(i-1>=0 && digs[i-1]==1)
                    cnt=1;
            }
        }
        sum=sum+cnt;

        return n-sum+1;

    }
};

int main(){
    Solution sol;
    sol.findIntegers(3);
    return 0;
}
