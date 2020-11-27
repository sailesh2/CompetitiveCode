class Cashier {
private:
	int customerCount = 0;
	int discountFreq;
	int discountValue;
	int prodPrice[205];

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    		discountFreq = n;
		discountValue = discount;
		for(int i=0;i<products.size();i++){
			prodPrice[products[i]]=prices[i];
}
    }

    double getBill(vector<int> product, vector<int> amount) {
    		customerCount=(customerCount+1)%discountFreq;
		double s =0 ;
for(int i=0;i<product.size();i++){
			s=s+prodPrice[product[i]]*amount[i];
}

if(customerCount==0){
	s=s-((discountValue*s)/100);
}

return s;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
