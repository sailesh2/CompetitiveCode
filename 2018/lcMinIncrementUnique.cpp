class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        long long int s=0,sm=0;
        set<int> finalA;
        int has[400005]={0};
        for(int i=0;i<A.size();i++){
            finalA.insert(A[i]);
            s=s+A[i];
            has[A[i]]++;
        }
        int orig=0;
        set<int>::iterator finalAIt = finalA.begin();
        while(finalA.size()<A.size()){
            int val = *finalAIt;
            orig=orig+has[val]-1;
            val++;
            while(finalA.size()<A.size() && finalA.count(val)==0){
                if(orig>0){
                    finalA.insert(val);
                    has[val]++;
                    val++;
                    orig--;
                }else{
                    break;
                }
            }
            finalAIt++;
        }
        finalAIt=finalA.begin();
        while(finalAIt!=finalA.end()){
            sm=sm+*finalAIt;
            finalAIt++;
        }
        return abs(sm-s);
    }
};
