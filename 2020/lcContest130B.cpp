class Solution {
private:
    bool found = false;
    string binNeg2="";

    vector<int> findMaxLimit(int n){
        long long int sm=0;
        vector<int> pos;
        long long int p=1;
        while(sm<n){
            sm=sm*4+1;
            pos.push_back(p);
            p=p*4;
        }
        return pos;
    }

    bool isPossible(int rem){
        vector<int> bin;
        while(rem>0){
            bin.push_back(rem%2);
            rem=rem/2;
        }
        for(int i=0;i<bin.size();i++){
            if(bin[i]==1 && i%2==0)
                return false;
        }
        return true;
    }

    void constructBinNeg2(int pos, int neg){
        vector<int> binpos;
        cout<<pos;
        int finalN = pos | neg;
        if(finalN==0){
            binNeg2.push_back('0');
            return;
        }
        while(finalN>0){
            binpos.push_back(finalN%2);
            finalN=finalN/2;
        }
        for(int i=binpos.size()-1;i>=0;i--){
            binNeg2.push_back((char)(binpos[i]+48));
        }
    }

    void baseNeg2(vector<int> lt, int sm, int index, int n){
        if(index==lt.size()){
            int rem = sm-n;
            if(rem>=0 && isPossible(rem)){
                found=true;
                constructBinNeg2(sm, rem);
            }
            return;
        }
        baseNeg2(lt, sm+lt[index], index+1, n);
        if(found)
            return;
        baseNeg2(lt, sm, index+1, n);
        return;
    }

public:
    string baseNeg2(int N) {
        vector<int> lt = findMaxLimit(N);

        baseNeg2(lt, 0, 0, N);
        return binNeg2;
    }
};
