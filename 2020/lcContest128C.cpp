class Solution {
private:
    int n;

    bool isPossible(vector<int>& A, vector<int>& B, int target){
        for(int i=0;i<n;i++){
            if(A[i]!=target && B[i]!=target){
                return false;
            }
        }
        return true;
    }

public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        n=A.size();

        if(!isPossible(A,B,A[0])  && !isPossible(A,B,B[0])){
            return -1;
        }

        int target = A[0];
        int ctr=0;
        for(int i=0;i<n;i++){
            if(A[i]!=target){
                ctr++;
            }
        }

        int ctr2=0;
        for(int i=0;i<n;i++){
            if(B[i]!=target){
                ctr2++;
            }
        }

        target = B[0];
        int ctr3=0;
        for(int i=0;i<n;i++){
            if(A[i]!=target){
                ctr3++;
            }
        }

        int ctr4=0;
        for(int i=0;i<n;i++){
            if(B[i]!=target){
                ctr4++;
            }
        }

        return min(min(min(ctr,ctr2),ctr3),ctr4);
    }
};
