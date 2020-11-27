class Solution {
private:
    pair<int,int> dp[50005];
    int n;
    vector<int> stones;
    int MIN=-1000000000;

    void clearDP(){
        for(int i=0;i<=n+3;i++)
            dp[i]=make_pair(0,0);
    }

    pair<int,int> greatest(int f, int s, int th){
        if(f>=s && f>=th)
            return make_pair(f,1);
        if(s>=f && s>=th)
            return make_pair(s,2);

        return make_pair(th,3);
    }

    pair<int,int> stoneGame(int index){
        if(index==n)
            return make_pair(0,0);

        int f=0;
        pair<int,int> nx;
        nx=dp[index+1].second==0?stoneGame(index+1):dp[index+1];
        f=stones[index];
        if(index+1+nx.second<n)
            f=f+dp[index+1+nx.second].first;


        int s=MIN;
        if(index+1<n){
            nx=dp[index+2].second==0?stoneGame(index+2):dp[index+2];
            s=stones[index] + stones[index+1];
            if(index+2+nx.second<n)
                s=s+dp[index+2+nx.second].first;
        }

        int th=MIN;
        if(index+2<n){
            nx=dp[index+3].second==0?stoneGame(index+3):dp[index+3];
            th=stones[index] + stones[index+1] + stones[index+2];
            if(index+3+nx.second<n)
                th=th+dp[index+3+nx.second].first;
        }

        pair<int,int> stonesTaken = greatest(f,s,th);
        dp[index]=stonesTaken;
        return stonesTaken;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        clearDP();
        stones = stoneValue;
        stoneGame(0);

        pair<int,int> aliceValues = dp[0];
        //cout<<aliceValues.first<<" "<<aliceValues.second;
        pair<int,int> bobValues = dp[aliceValues.second];

        if(aliceValues.first>bobValues.first)
            return "Alice";
        else if(aliceValues.first<bobValues.first)
            return "Bob";
        else
            return "Tie";
    }
};
