class Solution {
private:
    set<pair<int,string>> mp;

    void storeInMap(vector<vector<string>>& favoriteCompanies){
        for(int i=0;i<favoriteCompanies.size();i++){
            for(int j=0;j<favoriteCompanies[i].size();j++){
                mp.insert(make_pair(i,favoriteCompanies[i][j]));
            }
        }
    }

    vector<int> peopleInd(vector<vector<string>>& favoriteCompanies){
        storeInMap(favoriteCompanies);
        int cnt,cnt2;
        vector<int> ind;
        for(int i=0;i<favoriteCompanies.size();i++){
            cnt2=0;
            for(int k=0;k<favoriteCompanies.size();k++){
                cnt=0;
                if(k!=i){

                    for(int j=0;j<favoriteCompanies[i].size();j++){
                        string comp = favoriteCompanies[i][j];

                        if(mp.count(make_pair(k,comp))==0){
                            cnt=1;
                            break;
                        }
                    }
                }
                if(cnt==0){
                    cnt2=1;
                    break
                }
            }

            if(cnt2==0){
                ind.push_back(i);
            }
        }

        return ind;
    }
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        return peopleInd(favoriteCompanies);
    }
};
