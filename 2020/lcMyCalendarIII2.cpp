
class MyCalendarThree {
private:
    map<int,int> calendarCntMap;
    map<int,int>::iterator calendarCntMapIt;
    int maxCalendarCnt;

    void insertCalendar(int time, int val){
        calendarCntMapIt = calendarCntMap.find(time);
        if(calendarCntMapIt!=calendarCntMap.end()){
            val = val + calendarCntMapIt->second;
            calendarCntMap.erase(calendarCntMapIt);
        }
        calendarCntMap.insert(make_pair(time,val));
    }

    int getCalendarCount(int time){
        calendarCntMapIt = calendarCntMap.find(time);
        int val=0;
        if(calendarCntMapIt!=calendarCntMap.end()){
            val=calendarCntMapIt->second;
        }
        return val;
    }

    int maxCalendarCount(int time){
        maxCalendarCnt = max(maxCalendarCnt, getCalendarCount(time));
        return maxCalendarCnt;
    }

public:
    MyCalendarThree() {
        maxCalendarCnt=0;
    }

    int book(int start, int end) {
        insertCalendar(start,1);
        insertCalendar(end-1,-1);
        return maxCalendarCount(start);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
