class Solution {
private:
    int ops(int x, int y){
        int c=0;
        while(y>x){
            if(y%2!=0)
            {
                y++;
                c++;
            }
            y=y/2;
            c++;
        }
        return (x-y)+c;
    }
public:
    int brokenCalc(int x, int y) {
        return ops(x,y);
    }
};
