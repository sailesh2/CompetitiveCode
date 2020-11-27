class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int s=0;
        int frontC[cardPoints.size()];
        for(int i=0;i<cardPoints.size();i++){
            s=s+cardPoints[i];
            frontC[i]=s;
        }

        s=0;
        int l = cardPoints.size()-1;
        int rearC[cardPoints.size()];
        for(int i=cardPoints.size()-1;i>=0;i--){
            s=s+cardPoints[i];
            rearC[l-i]=s;
        }
        int maxi=0;
        for(int i=0;i<k-1;i++){
            maxi=max(maxi,frontC[i]+rearC[k-i-2]);
        }
        maxi=max(maxi,frontC[k-1]);
        maxi=max(maxi,rearC[k-1]);
        return maxi;
    }
};
