class Solution {
private:
    int mod=1000000007;
    int dp[100000][5];

    void clearDP(int n){
        for(int i=0;i<=n;i++){
            dp[i][0]=-1;
            dp[i][1]=-1;
            dp[i][2]=-1;
            dp[i][3]=-1;
            dp[i][4]=-1;
        }
    }

    int getIndex(char c){
        if(c=='a')
            return 0;
        else if(c=='e')
            return 1;
        else if(c=='i')
            return 2;
        else if(c=='o')
            return 3;
        else
            return 4;
    }

    int getNextPer(char c, int index, int n){
        int v=0;
        if(dp[index][getIndex(c)]==-1)
            v=(v+viowelPer(c,index,n))%mod;
        else
            v=(v+dp[index][getIndex(c)])%mod;

        return v;
    }

    int viowelPer(char prev, int index, int n){
        if(index==n){
            return 1;
        }

        int v=0;
        if(prev=='a'){
            v=(v+getNextPer('e',index+1,n))%mod;
        }else if(prev=='e'){
            v=(v+getNextPer('a',index+1,n))%mod;
            v=(v+getNextPer('i',index+1,n))%mod;
        }else if(prev=='i'){
            v=(v+getNextPer('a',index+1,n))%mod;
            v=(v+getNextPer('e',index+1,n))%mod;
            v=(v+getNextPer('o',index+1,n))%mod;
            v=(v+getNextPer('u',index+1,n))%mod;
        }else if(prev=='o'){
             v=(v+getNextPer('i',index+1,n))%mod;
             v=(v+getNextPer('u',index+1,n))%mod;
        }else{
             v=(v+getNextPer('a',index+1,n))%mod;
        }

        dp[index][getIndex(prev)]=v;
        return v;
    }
public:
    int countVowelPermutation(int n){
        clearDP(n);

        int v=0;
        v=(v+viowelPer('a',1,n))%mod;
        v=(v+viowelPer('e',1,n))%mod;
        v=(v+viowelPer('i',1,n))%mod;
        v=(v+viowelPer('o',1,n))%mod;
        v=(v+viowelPer('u',1,n))%mod;

        return v;
    }
};
