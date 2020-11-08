class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> sq;
        for(int i=0;i<A.size();i++){
            sq.push_back(A[i]*A[i]);
        }
        sort(sq.begin(),sq.end());
        return sq;
    }
};
