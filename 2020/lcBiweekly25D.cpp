class Solution {
private:
    vector<int> hatHash[40];
    map<pair<int,string>,int> dp;
    map<pair<int,string>,int>::iterator dpIt;
    int maxiIndex;
    vector<int> hatIndices;
    set<int> hatSet;
    int mod = 1000000007;

    bool allWear(string personTaken){
        for(int i=0;i<personTaken.length();i++){
            if(personTaken[i]=='0')
                return false;
        }
        return true;
    }

    int noOfWays(int index, string personTaken){
        if(allWear(personTaken))
            return 1;
        if(index==maxiIndex)
            return 0;
        int c=0;
        for(int j=index;j<maxiIndex;j++){
            int hatIndex = hatIndices[j];
            for(int i=0;i<hatHash[hatIndex].size();i++){
                int person = hatHash[hatIndex][i];
                if(personTaken[person]=='0'){
                    personTaken[person]='1';
                    dpIt = dp.find(make_pair(j+1,personTaken));
                    if(dpIt==dp.end())
                    c=(c+noOfWays(j+1,personTaken))%mod;
                    else
                    c=(c+dpIt->second)%mod;
                    personTaken[person]='0';
                }
            }
        }
        dp.insert(make_pair(make_pair(index,personTaken),c));
        return c;
    }
public:
    int numberWays(vector<vector<int>>& hats) {

        for(int i=0;i<hats.size();i++){
            for(int j=0;j<hats[i].size();j++){
                hatHash[hats[i][j]].push_back(i);
                if(hatSet.count(hats[i][j])==0){
                    hatIndices.push_back(hats[i][j]);
                    hatSet.insert(hats[i][j]);
                }
            }
        }
        maxiIndex = hatIndices.size();

        string personTaken;
        for(int i=0;i<hats.size();i++){
            personTaken.push_back('0');
        }
        int c=0;
        for(int i=0;i<maxiIndex;i++){
            dpIt = dp.find(make_pair(i,personTaken));
            if(dpIt==dp.end())
            c=(c+noOfWays(i,personTaken))%mod;
            else
            c=(c+dpIt->second)%mod;
        }
        return c;
    }
};
