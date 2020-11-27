
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        map<int,int> mp;
        map<int,int>::iterator mpIt;

        vector<int> v;
        for(int i=0;i<arr.size();i++){
            int ctr=0;
            mpIt=mp.find(arr[i]);
            if(mpIt==mp.end()){
                v.push_back(arr[i]);
            }else{
                ctr=mpIt->second;
                mp.erase(mpIt);
            }
            ctr++;
            mp.insert(make_pair(arr[i],ctr));
        }

        set<int> st;
        for(int i=0;i<v.size();i++){
            mpIt=mp.find(v[i]);
            int ctr=mpIt->second;
            if(st.count(ctr)>0){
                return false;
            }
            st.insert(ctr);
        }

        return true;
    }
};
