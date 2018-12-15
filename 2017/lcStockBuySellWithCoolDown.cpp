class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1)
            return 0;
        int cnt=0,sm1=0,sm2=0,tmp;
        int save,buy=-1,sell,a,b,c,d;
        int days=prices.size();
        for(int i=days-1;i>=1;i--){
            if(prices[i-1]<=prices[i]){
                if(cnt==0){
                    save=prices[i];
                    sell=i;
                }
                cnt=1;
            }else{
                if(cnt==1){
                    if(sell==buy-1){
                        a=sm1+prices[sell-1]-prices[i];
                        b=sm1+save-prices[i]+prices[buy]-prices[buy+1];
                        c=sm1+prices[buy]-prices[i];
                        d=sm2+save-prices[i];
                        tmp=sm1;
                        if(max(a,max(b,max(c,d)))>sm1){
                            sm1=max(a,max(b,max(c,d)));
                            buy=i;
                        }
                        sm2=tmp;
                    }else{
                        tmp=sm1;
                        sm1=sm1+save-prices[i];
                        buy=i;
                        sm2=tmp;
                    }
                }
                cnt=0;
            }
        }
        if(cnt==1){
            if(sell==buy-1){
                sm1=max(sm1+prices[sell-1]-prices[0],max(sm1+save-prices[0]+prices[buy]-prices[buy+1],sm1+prices[buy]-prices[0]));
                sm1=max(sm1,sm2+save-prices[0]);
            }
            else
                sm1=sm1+save-prices[0];
        }
        return max(sm1,sm2);
    }
};
