class Solution {
private:
    int smallFreqCount(string input){
        char minL='z';
        for(int i=0;i<input.length();i++){
            minL = min(minL, input[i]);
        }

        int c=0;
        for(int i=0;i<input.length();i++){
            if(input[i]==minL)
                c++;
        }

        return c;

    }

    vector<int> getSmallFreq(vector<string>& input){
        vector<int> smallFreq;
        for(int i=0;i<input.size();i++){
            smallFreq.push_back(smallFreqCount(input[i]));
        }
        return smallFreq;
    }
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> smallFreqQueries = getSmallFreq(queries);
        vector<int> smallFreqWords = getSmallFreq(words);

        vector<int> ans;
        for(int i=0;i<smallFreqQueries.size();i++){
            int c=0;
            for(int j=0;j<smallFreqWords.size();j++){
                if(smallFreqWords[j]>smallFreqQueries[i]){
                    c++;
                }
            }
            ans.push_back(c);
        }

        return ans;
    }
};
