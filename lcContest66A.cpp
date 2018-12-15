class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int has[200]={0};
        vector<int> p;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(B[j]==A[i] && has[j]==0){
                    has[j]=1;
                    p.push_back(j);
                }
            }
        }
        return p;
    }
};
