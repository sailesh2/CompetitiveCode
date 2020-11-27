class Solution {
private:
    int kfac(int n, int k){
        vector<int> facs;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                int f=i;
                int s=n/i;
                if(f==s)
                    facs.push_back(f);
                else{
                    facs.push_back(f);
                    facs.push_back(s);
                }
            }
        }
        sort(facs.begin(),facs.end());

        if(k<=facs.size())
            return facs[k-1];
        else
            return -1;
    }
public:
    int kthFactor(int n, int k) {
        return kfac(n,k);
    }
};
