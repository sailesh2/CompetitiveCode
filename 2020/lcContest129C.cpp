struct SightComparator {
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs < rhs;
    }

    bool operator() (const pair<int,int>& lhs, pair<int,int>& rhs) const {
        return lhs.first > rhs.first;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxi=0;
        int n=A.size();
        set<pair<int,int>> st;
        set<pair<int,int>>::iterator stIt;
        st.insert(make_pair(A[n-1]-n,n-1));
        for(int i=n-2;i>=0;i--){
            stIt = st.end();
            stIt--;
            pair<int,int> p = *stIt;
            if(i==n-2)
                maxi=A[i] + A[p.second] + i-p.second;
            else
                maxi=max(maxi,A[i] + A[p.second] + i-p.second);
            //cout<<p.second<<" ";
            st.insert(make_pair(A[i]-i+1,i));
        }
        return maxi;
    }
};
