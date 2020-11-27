class Solution {
public:
    string minInteger(string num, int k) {

        int n = num.length();
        set<pair<char,int>> st;
        set<pair<char,int>>::iterator stIt;
        for(int i=0;i<=min(n-1,k);i++){
            st.insert(make_pair(num[i],i));
        }

        int has[30005]={0};
        int f=0;
        string ans="";
        while(k>0 && f<n){
            stIt=st.begin();
            if(stIt==st.end())
                break;

            int ind=stIt->second;
            ans.push_back(stIt->first);
            k=k-(ind-f);
            has[ind]=1;
            st.erase(stIt);
            f++;
        }

        for(int i=0;i<n;i++){
            if(has[i]==0)
                ans.push_back(num[i]);
        }

        return ans;
    }
};
