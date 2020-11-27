#include<bits/stdc++.h>

using namespace std;


class MyCalendarThree {
private:
    struct Calendar{
        int time;
        int status;
    };

    struct CalendarComparator
    {
        bool operator()(const int& lhs, const int& rhs)
        {
            return lhs < rhs;
        }

        bool operator()(const Calendar& c1, const Calendar& c2)
        {
             if(c1.time==c2.time)
                return c1.status<c2.status;
             return c1.time<c2.time;
        }
    };
    set<Calendar,CalendarComparator> calList;
    set<Calendar,CalendarComparator>::iterator calListIt;

    int maxCalendarCount(){
        int ctr=0,maxi=0;

        for(calListIt = calList.begin();calListIt!=calList.end();calListIt++){
            Calendar calendar = *calListIt;
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
        calList.insert(createCalendar(start,0));
        calList.insert(createCalendar(end-1,1));
        return maxCalendarCount();
    }
};


int main(){
    MyCalendarThree* obj = new MyCalendarThree();
    cout<<obj->book(10,20);
    return 0;
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
