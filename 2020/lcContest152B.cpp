class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        long long int cals=0;
        int l=calories.size();
        if(k>l){
            return 0;
        }

        for(int i=0;i<k;i++){
            cals=cals+calories[i];
        }
        int wt=0;
        if(cals>upper)
            wt++;
        else if(cals<lower)
            wt--;

        for(int i=k;i<l;i++){
            cals=cals-calories[i-k];
            cals=cals+calories[i];

            if(cals>upper)
                wt++;
            else if(cals<lower)
                wt--;

        }
        return wt;
    }
};
