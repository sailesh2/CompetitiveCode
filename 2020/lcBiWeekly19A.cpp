class Solution {
public:
    int numberOfSteps (int num) {
        int s=0;
        while(num>0){
            if(num%2==0)
                num=num/2;
            else
                num--;
            s++;
        }
        return s;
    }
};
