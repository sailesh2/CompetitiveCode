class Solution {
private:
    vector<int> ans;
    map<int,int> has;

    void createConsDiffNums(int prev, int N, int K){
        if(N==0){
            if(has.find(prev) == has.end()){
                ans.push_back(prev);
                has.insert(make_pair(prev,1));
            }
            return;
        }

        int last = prev%10;
        if(last+K<=9){
            createConsDiffNums(prev*10+last+K, N-1, K);
        }
        if(last-K>=0){
            createConsDiffNums(prev*10+last-K, N-1, K);
        }
    }

    void createConsDiff(int N, int K){
        if(N==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
        }else{
            vector<int> arr;
            for(int i=1;i<=9;i++){
                createConsDiffNums(i,N-1,K);
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        createConsDiff(N,K);
        return ans;
    }
};
