class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int l= fronts.size();
        int mini=1000000000;
        int cnt2=0,cnt=0;
        int card;
        for(int i=0;i<l;i++){
            card=fronts[i];
            cnt=1;
            for(int j=0;j<l;j++){
                if(fronts[j]==card && backs[j]==card){
                    cnt=0;
                    break;
                }
            }
            if(cnt==1){
                mini=min(mini,card);
                cnt2=1;
            }
            card=backs[i];
            cnt=1;
            for(int j=0;j<l;j++){
                if(fronts[j]==card && backs[j]==card){
                    cnt=0;
                    break;
                }
            }
            if(cnt==1){
                mini=min(mini,card);
                cnt2=1;
            }
        }
        return cnt2==0?0:mini;
    }
};
