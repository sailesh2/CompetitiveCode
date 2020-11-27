class Solution {
private:
    int dp[101][101];
    int MAX=1000000000;

    void clearDP(){
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                    dp[i][j]=-1;

            }
        }
    }

    int dist(int first, int second, vector<int>& houses){

        int s=0;
        if(first<0){
            for(int i=0;i<=second;i++){
                s=s+abs(houses[i]-houses[second]);
            }

            return s;
        }

        for(int i=first;i<=second;i++){
            s=s+min(houses[i]-houses[first],houses[second]-houses[i]);
        }

        return s;
    }

    int dist(int first, vector<int>& houses){
        int s=0;
        for(int i=first;i<houses.size();i++){
            s=s+abs(houses[i]-houses[first]);
        }

        return s;
    }

    int minAlloc(int index, vector<int>& houses, int k){

        //cout<<"i"<<index<<"k"<<k<<"\n";
        if(k==0){
            return dist(index-1,houses);
        }

        if(index==houses.size()){
            return 0;
        }

        int mini=MAX;
        for(int i=index;i<houses.size();i++){
            if(dp[i+1][k-1]==-1)
                mini=min(mini,minAlloc(i+1,houses,k-1)+dist(index-1,i,houses));
            else
                mini=min(mini,dp[i+1][k-1]+dist(index-1,i,houses));
        }
        //cout<<"k--------"<<k<<"m"<<mini<<"\n";
        dp[index][k]=mini;
        return mini;
    }class Solution {
private:
    int dp[101][101];
    int MAX=1000000000;

    void clearDP(){
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                    dp[i][j]=-1;

            }
        }
    }

    int dist(int first, int second, vector<int>& houses){

        int s=0;
        if(first<0){
            for(int i=0;i<=second;i++){
                s=s+abs(houses[i]-houses[second]);
            }

            return s;
        }

        for(int i=first;i<=second;i++){
            s=s+min(houses[i]-houses[first],houses[second]-houses[i]);
        }

        return s;
    }

    int dist(int first, vector<int>& houses){
        int s=0;
        for(int i=first;i<houses.size();i++){
            s=s+abs(houses[i]-houses[first]);
        }

        return s;
    }

    int minAlloc(int index, vector<int>& houses, int k){

        if(k==0){
            return dist(index-1,houses);
        }

        if(index==houses.size()){
            return 0;
        }

        int mini=MAX;
        for(int i=index;i<houses.size();i++){
            if(dp[i+1][k-1]==-1)
                mini=min(mini,minAlloc(i+1,houses,k-1)+dist(index-1,i,houses));
            else
                mini=min(mini,dp[i+1][k-1]+dist(index-1,i,houses));
        }

        dp[index][k]=mini;
        return mini;
    }
public:
    int minDistance(vector<int>& houses, int k) {
        clearDP();
        sort(houses.begin(),houses.end());
        return minAlloc(0,houses,k);
    }
};
