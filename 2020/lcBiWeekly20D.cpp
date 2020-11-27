class Solution {
public:
int countOrders(int n) {
      	long long int s=1;
int mod=1000000007;

for(int i=2*n;i>=2;i=i-2){
	s=(s* ((i*(i-1))/2)%mod)%mod;
}

return s;
}
};
