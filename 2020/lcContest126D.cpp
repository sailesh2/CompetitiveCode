class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n=stones.size();
        vector<int> next;
        vector<int> next2;
        next=stones;
        int ans=0;
        while(1){
            int mini=1000000007;
            int save=-1;
            for(int i=0;i<n;i++){
                if(i+k<=n){
                    int sm=0;
                    for(int j=0;j<i+k;j++){
                        sm=sm+next[j];
                    }
                    if(sm<mini){
                        mini=sm;
                        save=j;
                    }
                }
            }

            if(save==-1)
                break;
            ans=ans+mini;
            for(int i=save;i<save+k;i++){
                next2.push_back(next[i]);
            }
            next=next2;
            next2.clear();
        }

        if(next.size()==0){
            return ans;
        }else{
            return -1;
        }
    }
};
