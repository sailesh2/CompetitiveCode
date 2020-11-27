
struct Trip{
    int pos;
    int status;
    int person;
};

bool TripComp(struct Trip a, struct Trip b){
    if(a.pos==b.pos)
        return a.status>b.status;
    return a.pos<b.pos;
}

class Solution {
private:
    int maxC;

    vector<Trip> convertToTrips(vector<vector<int>>& trips){
        vector<Trip> trs;
        for(int i=0;i<trips.size();i++){
            struct Trip t;
            t.person = trips[i][0];
            t.pos = trips[i][1];
            t.status = 0;
            trs.push_back(t);

            struct Trip t2;
            t2.person = trips[i][0];
            t2.pos = trips[i][2];
            t2.status = 1;
            trs.push_back(t2);
        }

        return trs;
    }

    bool canCarPoolAll(vector<vector<int>>& trips){
        vector<Trip> trs = convertToTrips(trips);
        sort(trs.begin(),trs.end(),TripComp);

        int tot=0;
        for(int i=0;i<trs.size();i++){
            struct Trip t =trs[i];
            if(t.status==0){
                tot = tot+t.person;
            }else{
                tot = tot-t.person;
            }

            if(tot>maxC){
                return false;
            }
        }

        return true;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        maxC = capacity;
        return canCarPoolAll(trips);
    }
};
