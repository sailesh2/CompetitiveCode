#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int ctr=0;
        long long int i=1,save=1,j,v1,v2;
        while(ctr<k){

            j=1;
            save=i;
            while(j*j<=i){
                if(i%j==0){
                    v1=j;
                    v2=i/j;
                    if(v1==v2){
                        if(v1<=m && v1<=n)
                            ctr++;

                    }else{
                        if(v1<=m && v2<=n)
                            ctr++;
                        if(v2<=m && v1<=n)
                            ctr++;
                    }

                    if(ctr>=k)
                        break;
                }
                j++;
            }
            i++;
        }
        return save;
    }
};
