#include<bits/stdc++.h>

using namespace std;


/**
 * Definition for an interval.*/

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };



struct timings{
    int val;
    int status;
};
bool fun(struct timings a, struct timings b){
    if(a.val==b.val){
        return a.status<b.status;
    }else
        return a.val<b.val;
}
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval> >& schedule) {
        vector<struct timings> timingsV;
        vector<Interval> intervals;
        for(int i=0;i<schedule.size();i++){
            intervals=schedule[i];

            for(int j=0;j<intervals.size();j++){
                struct timings a;
                a.val=intervals[j].start;
                a.status=0;
                timingsV.push_back(a);

                struct timings b;
                b.val=intervals[j].end;
                b.status=1;
                timingsV.push_back(b);
            }
        }
        vector<Interval> freeIntervals;
        int busy=0,save=-1;

        sort(timingsV.begin(),timingsV.end(),fun);

        for(int i=0;i<timingsV.size();i++){
            if(timingsV[i].status==0){
                busy++;
            }else{
                busy--;
            }
            if(busy==0){
                save=timingsV[i].val;
            }else if(busy==1){
                if(save!=-1){
                    Interval freeInterval;
                    freeInterval.start=save;
                    freeInterval.end=timingsV[i].val;
                    freeIntervals.push_back(freeInterval);
                    save=-1;
                }
            }
        }
        return freeIntervals;
    }
};
