class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long int sm=0;
        for(int i=0;i<A.size();i++){
            sm+=A[i];
        }

        set<long long int> hasLeft;
        long long int prefSm=A[0];
        hasLeft.insert(prefSm);
        for(int i=1;i<A.size()-1;i++){
            prefSm+=A[i];
            if(prefSm%2==0 && hasLeft.count(prefSm/2)>0 && sm-prefSm == prefSm/2){
                return true;
            }
            hasLeft.insert(prefSm);
        }
        return false;
    }
};
