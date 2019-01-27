class Solution {
private:
   vector<int> moves[10];
   long long int dp[10][50005];
   long long int mod = 1000000007;

   void initDP(int n){
       for(int i=0;i<10;i++){
            for(int j=0;j<=n+1;j++){
                dp[i][j]=-1;
            }
       }
   }

   void initMoves(){
       vector<int> v0;
       v0.push_back(4);
       v0.push_back(6);
       moves[0] = v0;

       vector<int> v1;
       v1.push_back(6);
       v1.push_back(8);
       moves[1] = v1;

       vector<int> v2;
       v2.push_back(7);
       v2.push_back(9);
       moves[2] = v2;

       vector<int> v3;
       v3.push_back(4);
       v3.push_back(8);
       moves[3] = v3;

       vector<int> v4;
       v4.push_back(3);
       v4.push_back(9);
       v4.push_back(0);
       moves[4] = v4;

       vector<int> v5;
       moves[5] = v5;

       vector<int> v6;
       v6.push_back(1);
       v6.push_back(7);
       v6.push_back(0);
       moves[6] = v6;

       vector<int> v7;
       v7.push_back(2);
       v7.push_back(6);
       moves[7] = v7;

       vector<int> v8;
       v8.push_back(1);
       v8.push_back(3);
       moves[8] = v8;

       vector<int> v9;
       v9.push_back(4);
       v9.push_back(2);
       moves[9] = v9;
   }

   long long int uniqueDials(int pos, int ctr, int n){
       if(ctr>=n-1)
        return 1;
       long long int sm=0;
       for(int i=0;i<moves[pos].size();i++){
            if(dp[moves[pos][i]][ctr+1]==-1)
                sm=(sm+uniqueDials(moves[pos][i],ctr+1,n))%mod;
            else
                sm=(sm+dp[moves[pos][i]][ctr+1])%mod;
       }
       dp[pos][ctr]=sm;
       return sm;
   }

   int noOfUniqueNos(int n){
       initDP(n);
       initMoves();
       long long int nos=0;
       for(int i=0;i<10;i++){
            nos = (nos + uniqueDials(i,0,n))%mod;
       }
       return nos;
   }

public:
    int knightDialer(int N) {
        return noOfUniqueNos(N);
    }
};
