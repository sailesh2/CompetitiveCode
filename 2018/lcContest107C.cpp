class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n=A.size();
        int i=0,j=n-1;
        while(i<j){
            while(i<j && A[i]==0){
                i++;
            }
            if(A[j]==1){
                if(middleEqual(i+1,j-1,A)){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }else{
                while(i<j && A[j]==0){
                    j--;
                }
            }
        }
    }
};
