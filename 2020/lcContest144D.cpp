class Solution {
private:

    int depth(string s){
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else
                ctr--;

        }
        return ctr;
    }

    int getStartIndexAtDepth(string s, int depth){
        int ctr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else
                ctr--;
            if(ctr==depth)
                return i;

        }
        return -1;

    }

    vector<int> maxDepthSplits(string s) {
        int totDepth = depth(s);

        int depth = totDepth/2+1;

        int startIndex = getStartIndexAtDepth(s,depth);

        int has[100005]={0};
        int ctr=0;
        for(int i=startIndex;i<s.length();i++){
            if(s[i]=='(')
                ctr++;
            else
                ctr--;
            has[i]=1;
            if(ctr==0){
                break;
            }
        }

        vector<int> splitIndices;
        for(int i=0;i<s.length();i++){
            splitIndices.push_back(has[i]);
        }
        return splitIndices;
    }

public:
    vector<int> maxDepthAfterSplit(string seq) {
        return maxDepthSplits(seq);
    }
};
