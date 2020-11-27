bool freqComp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first>b.first;
    return a.second>b.second;
}

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        vector<pair<int,int>> freqArr;
        map<int,int> mp;
        map<int,int>::iterator mpIt;

        for(int i=0;i<arr.size();i++){
            mpIt = mp.find(arr[i]);
            int f = 0;
            if(mpIt!=mp.end()){
                f=mpIt->second;
                mp.erase(mpIt);
            }
            f++;
            mp.insert(make_pair(arr[i],f));
        }

        for(int i=0;i<arr.size();i++){
            mpIt = mp.find(arr[i]);
            int f = mpIt->second;
            freqArr.push_back(make_pair(arr[i],f));
        }

        sort(freqArr.begin(),freqArr.end(),freqComp);

        int l = arr.size();
        l=l-k;
        set<int> st;
        int c=0;
        for(int i=0;i<l;i++){
            if(st.count(freqArr[i].first)==0){
                st.insert(freqArr[i].first);
                c++;
            }
        }

        return c;
    }
};
