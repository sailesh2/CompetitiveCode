#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size())
                return false;
        set<pair<string,string> > has;
        for(int i=0;i<pairs.size();i++){
            has.insert(pairs[i]);
        }
        int cnt=0;
        for(int i=0;i<words1.size();i++){
            if(words1[i].compare(words2[i])!=0){
                if(has.count(make_pair(words1[i],words2[i]))==0 && has.count(make_pair(words2[i],words1[i]))==0){
                    cnt=1;
                    break;
                }
            }
        }
        return cnt==0;
    }
};
