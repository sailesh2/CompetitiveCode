class Solution {
public:
    bool queryString(string S, int N) {
        long long int sm=0;
        set<long long int> has;
        for(int i=0;i<S.length();i++){
            sm=0;
            for(int j=i;j<S.length();j++){
                sm=sm*2+(int)S[j]-48;
                if(sm>N)
                    break;
                else{
                    if(sm>0)
                    has.insert(sm);
                }
            }
        }
        return has.size()==N;
    }
};
