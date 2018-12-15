class Solution {
private:
    int getNext(int n){
        int next=0;
        while(n>0){
            next=next+(n%10)*(n%10);
            n=n/10;
        }
        return next;
    }
    bool isHappyRecur(int n){
        set<int> has;
        int cnt=0;
        while(1){
            if(n==1){
                cnt=1;
                break;
            }
            if(has.count(n)>0){
                break;
            }
            has.insert(n);
            n=getNext(n);
        }
        return cnt==1;
    }
public:
    bool isHappy(int n) {
        return isHappyRecur(n);
    }
};
