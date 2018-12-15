#include<bits/stdc++.h>

using namespace std;


  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 bool fun(Interval a, Interval b){
    return a.start<b.start;
 }
class Solution {
private:
    map<pair<int,int> ,int> mp;
    map<pair<int,int> ,int>::iterator mpIt;

    int getPos(Interval interval){
        mpIt=mp.find(make_pair(interval.start,interval.end));
        if(mpIt!=mp.end())
            return mpIt->second;
        else
            return -1;
    }

    int findMin(vector<Interval>& intervals,int toFind){
        int ctr=1;
        int save=-1;
        int save2=-1;

        int k=intervals.size();
        while(1){
            while(save+ctr<k && intervals[save+ctr].start<toFind){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        if(save+1==intervals.size())
            return -1;
        return getPos(intervals[save+1]);
    }

public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> ans;
        vector<Interval> intervals2=intervals;
        for(int i=0;i<intervals.size();i++){
            mp.insert(make_pair(make_pair(intervals[i].start,intervals[i].end),i));
        }
        sort(intervals.begin(),intervals.end(),fun);
        for(int i=0;i<intervals2.size();i++){
            ans.push_back(findMin(intervals,intervals2[i].end));
        }
        return ans;
    }
};
