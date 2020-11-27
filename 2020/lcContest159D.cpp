struct Schedule{
    int startT;
    int endT;
    int profit;
};

bool scheduleComp(Schedule a, Schedule b){
    return a.endT<b.endT;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Schedule> schedules;

        for(int i=0;i<startTime.size();i++){
            Schedule sch;
            sch.startT=startTime[i];
            sch.endT=endTime[i];
            sch.profit=profit[i];

            schedules.push_back(sch);
        }

        sort(schedules.begin(),schedules.end(),scheduleComp);

        map<int,int> sortedSchedule;
        map<int,int>::iterator sortedScheduleIt;
        int maxi=0;
        int maxT=0;
        for(int i=0;i<schedules.size();i++){
            Schedule sch = schedules[i];

            int v=0;
            if(sortedSchedule.size()>0){
            sortedScheduleIt = sortedSchedule.upper_bound(sch.startT);
            bool isBeg = sortedScheduleIt == sortedSchedule.begin();
            sortedScheduleIt--;

            if(!isBeg && sortedScheduleIt!=sortedSchedule.end()){
                v=sortedScheduleIt->second;
            }
            }
            if(v+sch.profit>maxi){
                maxi=v+sch.profit;
                if(sch.endT==maxT){
                    sortedScheduleIt=sortedSchedule.end();
                    sortedScheduleIt--;
                    sortedSchedule.erase(sortedScheduleIt);
                }
                maxT=sch.endT;
                sortedSchedule.insert(make_pair(sch.endT,maxi));
            }
        }

        return maxi;
    }
};
