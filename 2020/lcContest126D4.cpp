class Solution {
private:
    int n,k;
    vector<int> stoneCosts;
    pair<int,int> dp[35][35];
    int sum[35]={0};

    void preProcess(vector<int>& stones, int K){
        stoneCosts = stones;
        n=stoneCosts.size();
        k=K;

        for(int i=0;i<35;i++){
            for(int j=0;j<35;j++){
                    dp[i][j]=make_pair(-2,0);

            }
        }

        int s=0;
        for(int i=0;i<n;i++){
            s=s+stoneCosts[i];
            sum[i]=s;
        }
    }

    int mergeCost(int i, int j){
        if(i==0)
            return sum[j];
        return sum[j]-sum[i-1];
    }

    bool isPossible(int i, int j){
        return (j-i)%(k-1) == 0;
    }

    pair<int,int> mergeStones(int start, int end, int ctr, int cnt){
        cout<<start<<" "<<end<<"\n";


        if(ctr==k){
            if(isPossible(start,end)){
                if(dp[start][end].first==-2)
                return mergeStones(start,end,1,1);
                else
                return dp[start][end];
            }else{
                return make_pair(-1,0);
            }
        }

        if(end-start+1==k){
            if(cnt==1)
            return make_pair(mergeCost(start,end),mergeCost(start,end));
            else
            return make_pair(-1,0);
        }

        if(start==end){
            if(cnt==1)
            return make_pair(mergeCost(start,end),0);
            else
            return make_pair(-1,0);
        }

        int minCost=100000000;
        int p=0;
        pair<int,int> pL,pR;
        int first,second;
        for(int i=start+1;i<=end;i++){

            if(isPossible(start,i-1)){

                if(dp[start][i-1].first==-2){
                    pL =mergeStones(start,i-1,1,1);
                }else{
                    pL=dp[start][i-1];
                }

                if(pL.first!=-1){
                    if(dp[i][end].first==-2){
                        pR = mergeStones(i,end, ctr+1,2);
                    }
                    else{
                        pR= dp[i][end];
                    }

                    if(pR.first!=-1){
                        p=1;
                        if(pL.first+pL.second + pR.first+pR.second < minCost){
                            minCost=pL.first+pL.second + pR.first+pR.second;
                            first=pL.first+pR.first;
                            second=pL.second+pR.second;
                        }
                    }
                }
            }
        }

        if(p==0){
            minCost=-1;
            first=-1;
            second=0;
        }
        else{
            if(ctr==1)
                second=second+first;
        }
        cout<<"returnz"<<minCost<<"\n";
        dp[start][end]=make_pair(first,second);
        return dp[start][end];
    }
public:
    int mergeStones(vector<int>& stones, int K) {
        preProcess(stones,K);
        pair<int,int> p= mergeStones(0,n-1,1,1);
        if(p.first==-1)
            return -1;
        return p.second;
    }
};
