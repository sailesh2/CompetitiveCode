class SnapshotArray {
private:
    map<int,vector<pair<int,int> > > snapList;
    map<int,vector<pair<int,int> > >::iterator snapListIt;
    int snapCnt;


    int binSearch(vector<pair<int,int> >& snapValues, int snapId){
        int ctr=1;
        int save=-1;
        int save2=-1;
        int k=snapValues.size();
        while(1){
            while(save+ctr<k && snapValues[save+ctr].first<=snapId){
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
            return 0;
        return snapValues[save].second;
    }

public:
    SnapshotArray(int length) {

        snapCnt=-1;
    }

    void set(int index, int val) {

        snapListIt = snapList.find(index);

        if(snapListIt!=snapList.end()){
            vector<pair<int,int> >& v=snapListIt->second;
            if(v.size()==0 || v[v.size()-1].first!=(snapCnt+1)){
                v.push_back(make_pair(snapCnt+1,val));
            }else{
                v[v.size()-1]=make_pair(snapCnt+1,val);
            }
        }else{
            vector<pair<int,int> > v;
            v.push_back(make_pair(snapCnt+1,val));

            snapList.insert(make_pair(index,v));
        }

    }

    int snap() {
        snapCnt++;
        return snapCnt;
    }

    int get(int index, int snap_id) {
        snapListIt = snapList.find(index);
        if(snapListIt==snapList.end())
            return 0;
        vector<pair<int,int> >& snapValues = snapListIt->second;
        return binSearch(snapValues, snap_id);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
