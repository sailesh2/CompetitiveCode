struct Calendar{
    int time;
    int status;
};

bool calendarComparator(Calendar c1, Calendar c2){
    if(c1.time==c2.time)
        return c1.status<c2.status;
    return c1.time<c2.time;
}

class MyCalendarThree {
private:
    vector<Calendar> calList;

    int maxCalendarCount(){
        int ctr=0,maxi=0;
        for(int i=0;i<calList.size();i++){
            Calendar calendar = calList[i];
            if(calendar.status==0)
                ctr++;
            else
                ctr--;

            maxi=max(maxi,ctr);
        }
        return maxi;
    }

    Calendar createCalendar(int time, int status){
        Calendar calendar;
        calendar.time=time;
        calendar.status=status;
        return calendar;
    }

public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        calList.push_back(createCalendar(start,0));
        calList.push_back(createCalendar(end-1,1));
        sort(calList.begin(), calList.end(), calendarComparator);
        return maxCalendarCount();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
