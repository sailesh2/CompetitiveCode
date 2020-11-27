class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int> > groups;
        map<int,int> grpMap;
        map<int,int>::iterator grpMapIt;
        int ctr=-1;
        for(int i=0;i<groupSizes.size();i++){
            int s=groupSizes[i];
            grpMapIt=grpMap.find(s);
            if(grpMapIt==grpMap.end()){
                ctr++;
                vector<int> v;
                v.push_back(i);
                groups.push_back(v);
                grpMap.insert(make_pair(s,ctr));
            }else{
                int index=grpMapIt->second;
                if(groups[index].size()<s){
                    groups[index].push_back(i);
                }else{
                    ctr++;
                    vector<int> v;
                    v.push_back(i);
                    groups.push_back(v);
                    grpMap.erase(grpMapIt);
                    grpMap.insert(make_pair(s,ctr));
                }
            }
        }
        return groups;
    }
};
