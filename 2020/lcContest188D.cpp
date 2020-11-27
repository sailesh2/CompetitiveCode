class Solution {
private:
    int dp[51][51][11];
    int apples[51][51];
    int n,m;
    int mod = 1000000007;

    void clearDP(){
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                for(int k=0;k<11;k++)
                    dp[i][j][k]=-1;
            }
        }
    }

    void storeApples(vector<string> pizza){
        int col[51][51];


        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++)
                col[i][j]=0;
        }



        for(int i=0;i<m;i++){
            int a=0;
            for(int j=0;j<n;j++){
                if(pizza[j][i]=='A')
                    a++;
                col[j][i]=a;
            }
        }



        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<m;j++){
                a=a+col[i][j];
                apples[i][j]=a;
            }
        }


    }

    bool areApplesPresent(int ru, int rd, int cl, int cr){
        return (apples[rd-1][cr-1] - ((cl-1>=0)?apples[rd-1][cl-1]:0) - ((ru-1>=0)?apples[ru-1][cr-1]:0) + ((ru-1>=0 && cl-1>=0)?apples[ru-1][cl-1]:0) )>0;
    }

    int ways(int ru, int rd, int cl, int cr, int k){
        int app=0;
        if(k>1){
                for(int i=ru+1;i<rd;i++){
                    if(areApplesPresent(ru,i,cl,cr) && areApplesPresent(i,rd,cl,cr)){
                        if(dp[i][cl][k-1]==-1)
                            app=(app+ways(i,rd,cl,cr,k-1))%mod;
                        else
                            app=(app+dp[i][cl][k-1])%mod;
                    }
                }
                for(int i=cl+1;i<cr;i++){
                    if(areApplesPresent(ru,rd,cl,i) && areApplesPresent(ru,rd,i,cr)){
                        if(dp[ru][i][k-1]==-1)
                            app=(app+ways(ru,rd,i,cr,k-1))%mod;
                        else
                            app=(app+dp[ru][i][k-1])%mod;
                    }
                }

        }else{
            app = areApplesPresent(ru,rd,cl,cr)?1:0;
        }

        dp[ru][cl][k]=app;
        return app;
    }
public:
    int ways(vector<string>& pizza, int k) {
        clearDP();
        n=pizza.size();
        m=pizza[0].length();

        storeApples(pizza);
        return ways(0,n,0,m,k);
    }
};
