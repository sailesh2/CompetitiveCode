class TimeMap {
private:
    map<string,vector<int>> dictKeyTime;
    map<string,vector<int>>::iterator dictKeyTimeIt;


    map<int,string> dictTimeValue;
    map<int,string>::iterator dictTimeValueIt;

    int binSear(vector<int> pc2, int cost){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && pc2[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    if(save==-1)
        return -1;
    return p2[save];
}


public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        dictKeyTimeIt = dictKeyTime.find(key);
        vector<int> st;
        if(dictKeyTimeIt!=dictKeyTime.end()){
            st = dictKeyTimeIt->second;
            dictKeyTime.erase(dictKeyTimeIt);
        }
        st.push_back(timestamp);
        dictKeyTime.insert(make_pair(key,st));
        dictTimeValue.insert(make_pair(timestamp,value));
    }

    string get(string key, int timestamp) {
        dictKeyTimeIt = dictKeyTime.find(key);
        vector<int> st;
        if(dictKeyTimeIt!=dictKeyTime.end()){
            st = dictKeyTimeIt->second;
            int val = binSear(st,timestamp);
            if(val==-1)
                return "":
            dictTimeValueIt = dictTimeValue.find(val);
            if(dictTimeValueIt == dictTimeValue.end()){
                return "";
            }
            return dictTimeValueIt->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
