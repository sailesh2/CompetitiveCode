class Solution {
private:
    bool possibleOne(int freq, int cnt){
        if(cnt==1)
            return true;
        if(freq==1)
            return true;
        return false;
    }

    bool possibleTwo(int freq1, int cnt1, int freq2, int cnt2){
        if(freq1==1 && cnt1==1)
            return true;
        if(freq2==1 && cnt2==1)
            return true;

        if(freq1==1 && cnt1-cnt2==1)
            return true;

        if(freq2==1 && cnt2-cnt1==1)
            return true;

        return false;
    }

public:
    int maxEqualFreq(vector<int>& nums) {
        int maxi=0;
        int disFreq=0;
        int freqCnt[100005]={0};
        int cnt[100005]={0};
        int oneCnt;
        set<int> st;
        set<int>::iterator stIt;
        for(int i=0;i<nums.size();i++){

            if(freqCnt[cnt[nums[i]]]==1){
                freqCnt[cnt[nums[i]]]=0;
                disFreq--;

            }else if(freqCnt[cnt[nums[i]]]>1){
                freqCnt[cnt[nums[i]]]--;
            }

            stIt=st.find(cnt[nums[i]]);
            if(stIt!=st.end())
                    st.erase(st.find(cnt[nums[i]]));

            cnt[nums[i]]++;
                    st.insert(cnt[nums[i]]);

            freqCnt[cnt[nums[i]]]++;
            if(freqCnt[cnt[nums[i]]]==1){
                disFreq++;

            }


            if(disFreq==1){
                stIt = st.begin();
                int oneCnt = *stIt;
                if(possibleOne(freqCnt[oneCnt],oneCnt)){
                    maxi=i+1;
                }
            }else if(disFreq==2){

                stIt = st.begin();
                int oneCnt = *stIt;
                stIt++;
                int twoCnt = *stIt;
                if(possibleTwo(freqCnt[oneCnt],oneCnt,freqCnt[twoCnt],twoCnt)){
                    maxi=i+1;
                }
            }
        }

        return maxi;
    }
};
