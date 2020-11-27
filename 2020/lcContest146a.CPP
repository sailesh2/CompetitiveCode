class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int> , int> dominoMap;
        map<pair<int,int> , int>::iterator dominoMapIt;
        int ans=0;
        for(int i=0;i<dominoes.size();i++){
            int l=dominoes[i][0];
            int b=dominoes[i][1];

            dominoMapIt=dominoMap.find(make_pair(l,b));
            int c=0;

            if(dominoMapIt!=dominoMap.end()){
                c=dominoMapIt->second;
                dominoMap.erase(dominoMapIt);
            }
            ans=ans+c;
            dominoMap.insert(make_pair(make_pair(l,b),c+1));
            if(l!=b){

            dominoMapIt=dominoMap.find(make_pair(b,l));
            c=0;
            if(dominoMapIt!=dominoMap.end()){
                c=dominoMapIt->second;
            }
            ans=ans+c;
            }
        }
        return ans;
    }
};
