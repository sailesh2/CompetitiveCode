class Solution {
private:
    int gcd(int a , int b)
    {
       if(b==0) return a;
       a%=b;
       return gcd(b,a);
    }

public:
    bool isGoodArray(vector<int>& nums) {
        int g=nums[0];
        for(int i=1;i<nums.size();i++){
            g=gcd(g,nums[i]);
        }
        return g==1;
    }
};
