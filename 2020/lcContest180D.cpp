
bool compPerf(pair<long long int,long long int> a, pair<long long int,long long int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

class Solution {
private:
    long long int mod=1000000007;
public:
    long long int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<long long int,long long int> > perf;

        for(long long int i=0;i<n;i++){
            perf.push_back(make_pair(speed[i],efficiency[i]));
        }

        sort(perf.begin(),perf.end(),compPerf);

        long long int maxk[n];
        multiset<long long int> st;
        multiset<long long int>::iterator stIt;
        long long int sm=0;
        long long int ctr=0;
        for(long long int i=n-1;i>=0;i--){
            if(ctr<k-1){
                st.insert(perf[i].first);
                sm=(sm+perf[i].first);
                ctr++;
            }else{
                stIt=st.begin();
                if(stIt!=st.end()){
                    long long int v=*stIt;
                    if(v<perf[i].first){
                        sm=sm-v;
                        sm=(sm+perf[i].first);
                        st.erase(stIt);
                        st.insert(perf[i].first);
                    }
                }
            }
            maxk[i]=sm;
        }

        long long int maxi=0;
        for(long long int i=0;i<n;i++){
            long long int v;
            if(i+1<n)
                v=(perf[i].second*((perf[i].first+maxk[i+1])));
            else
                v=(perf[i].second*perf[i].first);
            maxi=max(maxi,v);
        }
        return maxi%mod;
    }
};
