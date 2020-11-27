class Solution {
private:
    set<string> has;
    string word;
    int dp[100005];

    void clearDP(){
        int l = word.length();
        for(int i=0;i<=l;i++)
            dp[i]=-1;
    }

    bool wordBreak(int index){

        int l = word.length();
        if(index==l)
            return true;
        string s="";

        for(int i=index;i<l;i++){
            s.push_back(word[i]);
            if(has.count(s)>0){
                if(dp[i+1]==-1){
                    if(wordBreak(i+1)){
                        dp[index]=0;
                        return true;
                    }
                }else{
                    if(dp[i+1]==0){
                        dp[index]=0;
                        return true;
                    }
                }
            }
        }

        dp[index]=1;
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
            has.insert(wordDict[i]);
        }

        word=s;
        clearDP();

        return wordBreak(0);
    }
};
