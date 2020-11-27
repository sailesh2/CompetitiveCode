
class MyCalendarThree {
private:
    multiset<pair<int,int>> calListMap;
    multiset<pair<int,int>>::iterator calListMapIt;

    int maxCalendarCount(){
        int ctr=0,maxi=0;

        for(calListMapIt = calListMap.begin();calListMapIt!=calListMap.end();calListMapIt++){
            ctr = ctr + (calListMapIt->second);
            maxi=max(maxi,ctr);
        }
        return maxi;
    }

public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        calListMap.insert(make_pair(start,1));
        calListMap.insert(make_pair(end,-1));
        return maxCalendarCount();
    }
};
