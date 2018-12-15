class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(),A.end());
        map<int,long long int> has;
        map<int,long long int>::iterator hasIt;
        map<int,long long int>::iterator hasIt2;
        set<int> done;

        long long int ctr=0;
        long long int s;
        long long int num1;
        long long int num2;
        int mod=1000000007;
        for(int i=0;i<A.size();i++){
            ctr=ctr;
            s=1;
            done.clear();
            for(int j=0;j<i;j++){

                if(done.count(A[j])>0)
                    continue;
                if(A[i]%A[j]==0){
                    hasIt = has.find(A[i]/A[j]);
                    if(hasIt!=has.end()){
                        hasIt2=has.find(A[j]);
                        num1=hasIt->second;
                        num2=hasIt2->second;

                        if(A[j]==A[i]/A[j]){
                            s=(s+(num1*num1)%mod)%mod;
                        }else{
                            s=(s+((num1*num2)%mod*2)%mod)%mod;
                        }
                        done.insert(A[j]);
                        done.insert(A[i]/A[j]);
                    }
                }
            }
            has.insert(make_pair(A[i],s));
            ctr=(ctr+s)%mod;
        }
        return ctr;
    }
};
