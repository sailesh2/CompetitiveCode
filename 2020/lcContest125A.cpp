class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int has[1002]={0};
        set<int> trusted[1002];
        for(int i=0;i<trust.size();i++){
            has[trust[i][0]]=1;
            trusted[trust[i][0]].insert(trust[i][1]);
        }
        int ctr=0;
        int townJudge=-1;
        for(int i=1;i<=N;i++){
            if(has[i]==0){
                ctr++;
                townJudge=i;
            }
        }

        if(ctr==0 || ctr>1)
            return -1;
        for(int i=1;i<=N;i++){
            if(i!=townJudge){
                if(trusted[i].count(townJudge)==0){
                        return -1;

                }
            }
        }
        return townJudge;
    }
};
