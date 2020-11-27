class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int cnt=0;
        int s=target[0];
        for(int i=0;i<target.size()-1;i++){
            if(target[i]<target[i+1]){
                s=s+target[i+1]-target[i];
                cnt=1;
            }else{
                if(cnt==0 && i!=0)
                    s=s+target[i];
                    cnt=1;
            }
        }
        return s;
    }
};
