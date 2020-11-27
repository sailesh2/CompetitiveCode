class Solution {
private:
    int clumsyFact(int n){
        int stk[n+1];
        int top=-1;
        stk[++top]=n;
        n--;
        int ctr=0;
        while(n>0){

            switch(ctr){
            case 0:
                stk[top] = stk[top]*n;
                break;
            case 1:
                stk[top] = stk[top]/n;
                break;
            case 2:
                stk[++top] = n;
                break;
            case 3:
                stk[++top] = -1*n;
                break;
            default:
                break;
            }

            ctr=(ctr+1)%4;
            n--;
        }
        int sm=0;
        for(int i=0;i<=top;i++){
            sm=sm+stk[i];
        }
        return sm;
    }
public:
    int clumsy(int N) {
        return clumsyFact(N);
    }
};
