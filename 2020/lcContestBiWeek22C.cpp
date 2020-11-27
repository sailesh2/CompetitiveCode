bool powerComp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

class Solution {
private:
    int dp[1006];

    void clearDP(){
        for(int i=0;i<=1005;i++)
            dp[i]=-1;
    }

    int getP(int v){

        if(dp[v]!=-1)
            return dp[v];

        if(v==1)
            return 0;

        int power;
        if(v%2==0)
        power=getP(v/2)+1;
        else
        power=getP(3*v+1)+1;

        dp[v]=power;
        return power;
    }
public:
    int getKth(int lo, int hi, int k) {
        clearDP();

        vector<pair<int,int>> pv;

        for(int i=lo;i<=hi;i++){
            pv.push_back(make_pair(getP(i),i));
        }

        sort(pv.begin(),pv.end(),powerComp);

        return pv[k-1].second;
    }
};
