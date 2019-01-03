class Solution {
private:
    int deletes = 0;
    int posDels[300]={0};

    void noOfdeletesRequired(string a, string b){

        for(int i = 0;i<a.length();i++){
            if(posDels[i]==0){
                if(a[i]>b[i]){
                    deletes++;
                    posDels[i]=1;
                }else if(a[i]<b[i]){
                    return;
                }
            }
        }
    }

    void minDeletion(vector<string>& A){

        int len = A.size();
        for(int i=0;i<len-1;i++){
            noOfdeletesRequired(A[i], A[i+1]);
        }
    }
public:
    int minDeletionSize(vector<string>& A) {
        minDeletion(A);
        return deletes;
    }
};
