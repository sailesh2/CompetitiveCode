class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hMaxi=0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        for(int i=0;i<horizontalCuts.size();i++){
            if(i==0){
                hMaxi=max(hMaxi,horizontalCuts[i]);
            }else{
                hMaxi=max(hMaxi,horizontalCuts[i]-horizontalCuts[i-1]);
            }
        }
        hMaxi=max(hMaxi,h-horizontalCuts[horizontalCuts.size()-1]);

        int vMaxi=0;
        sort(verticalCuts.begin(), verticalCuts.end());
        for(int i=0;i<verticalCuts.size();i++){
            if(i==0){
                vMaxi=max(vMaxi,verticalCuts[i]);
            }else{
                vMaxi=max(vMaxi,verticalCuts[i]-verticalCuts[i-1]);
            }
        }
        vMaxi=max(vMaxi,w-verticalCuts[verticalCuts.size()-1]);

        long long int mod = 1000000007;
        long long int ans = ((long long int)hMaxi*(long long int)vMaxi)%mod;
        return ans;
    }
};
