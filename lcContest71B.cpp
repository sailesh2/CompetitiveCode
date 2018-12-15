class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(),answers.end());
        int totalRabbits=0;
        int currGrpTotalRabbits=0;
        int currGrpUsedRabbits=0;
        int cnt=0;
        for(int i=answers.size()-1;i>=0;i--){
            if(cnt==0){
                totalRabbits=totalRabbits+answers[i]+1;
                currGrpTotalRabbits=answers[i]+1;
                currGrpUsedRabbits=1;
                cnt=1;
            }else{
                if(currGrpTotalRabbits-currGrpUsedRabbits>=currGrpTotalRabbits-answers[i]){
                    currGrpUsedRabbits=currGrpUsedRabbits+currGrpTotalRabbits-answers[i];
                }else{
                    totalRabbits=totalRabbits+answers[i]+1;
                    currGrpTotalRabbits=answers[i]+1;
                    currGrpUsedRabbits=1;
                    cnt=1;
                }
            }
            if(currGrpTotalRabbits==currGrpUsedRabbits)
                cnt=0;
        }
        return totalRabbits;
    }
};
