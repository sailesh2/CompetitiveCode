class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int save=-1,sm=0;
        for(int i=0;i<gas.size();i++){
            sm=sm+gas[i]-cost[i];
            if(save==-1 && sm>=0){
                save=i;
            }
            if(sm<0){
                sm=0;
                save=-1;
            }
        }
        for(int i=0;i<save;i++){
            sm=sm+gas[i]-cost[i];
            if(sm<0){
                save=-1;
                break;
            }
        }
        return save;
    }
};
