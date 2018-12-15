class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row[10005]={0};
        int col[10005]={0};
        int has[10005]={0};
        for(int i=0;i<stones.size()){
            row[stones[i][0]]++;
            col[stones[i][1]]++;
        }
        int ctr=0;
        for(int j=0;j<stones.size();j++){
            int maxi=0;
            int save==-1;
            for(int i=0;i<stones.size();i++){
                if(has[i]==0){
                int rem = row[stones[i][0]]+col[stones[i][1]-2;
                if(rem>maxi){
                    maxi=rem;
                    save=i;
                }
                }
            }
            if(save==-1)
                break;
            has[save]=1;
            ctr++;
            row[stones[save][0]]--;
            col[stones[save][1]]--;
        }
        return ctr;
    }
};
