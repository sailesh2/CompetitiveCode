class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int sum=0,sum2,save;
        vector<int> offer;
        for(int i=0;i<price.size();i++){
            sum=sum+price[i]*needs[i];
        }
        while(1){
            sum2=sum+1;
            save=-1;
            for(int i=0;i<special.size();i++){
                offer=special[i];
                sum2=offer[offer.size()-1];
                for(int j=0;j<needs.size();j++){
                    sum2=sum2+price[j]*(max(0,needs[j]-offer[j]));
                }
                if(sum2<sum){
                    sum=sum2;
                    save=i;
                }
            }
            if(save==-1)
                break;
            offer=special[save];
            for(int i=0;i<needs.size();i++){
                needs[i]=max(0,needs[i]-offer[i]);
            }
        }
        return sum;
    }
};
