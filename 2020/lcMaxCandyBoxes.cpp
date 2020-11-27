class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int openned[1001]={0};
        int haveKeys[1001]={0};
        int haveBox[1001]={0};
        int c=0;

        for(int i=0;i<initialBoxes.size();i++){
            haveBox[initialBoxes[i]]=1;
        }

        while(1){
            int cnt=0;
            int save=-1;
            for(int i=0;i<initialBoxes.size();i++){
                int box = initialBoxes[i];
                if(openned[box]==0){
                    if(status[box]==1 || haveKeys[box]==1){
                        cnt=1;
                        save=box;
                        openned[box]=1;
                        break;
                    }
                }
            }

            if(cnt==0)
                break;

            c = c + candies[save];
            for(int i=0;i<keys[save].size();i++){
                haveKeys[keys[save][i]]=1;
            }

            for(int i=0;i<containedBoxes[save].size();i++){
                if(haveBox[containedBoxes[save][i]]==0){
                    haveBox[containedBoxes[save][i]]=1;
                    initialBoxes.push_back(containedBoxes[save][i]);
                }
            }
        }

        return c;
    }
};
