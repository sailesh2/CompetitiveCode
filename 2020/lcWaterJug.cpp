class Solution {
private:
    int gcd(int a , int b)
    {
       if(b==0) return a;
       a%=b;
       return gcd(b,a);
    }

public:
    bool canMeasureWater(int x, int y, int z) {
        return z==0 || ( (x!=0 || y!=0)
            && z%gcd(x,y) == 0
            && z/gcd(x,y) <= x+y);
    }
};
