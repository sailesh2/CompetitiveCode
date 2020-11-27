class RecentCounter {
private:
    vector<int> pings;
public:
    RecentCounter() {

    }

    int ping(int t) {
        while(pings.begin()!=pings.end()){
            if(t-3000>pings[0]){
                pings.erase(pings.begin());
            }else{
                break;
            }
        }
        pings.push_back(t);
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
