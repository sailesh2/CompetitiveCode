#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int s=0,c,n=A.size(),diff;
        for(int i=0;i<n;i++){
            if(i+2<n && A[i+2]-A[i+1]==A[i+1]-A[i]){
                diff=A[i+1]-A[i];
                int j;
                for(j=i+3;j<n;j++){
                    if(A[j]-A[j-1]!=diff)
                        break;
                }
                c=j-i;
                s=s+(c*(c+1))/2-(2*c-1);
                i=j-1;
            }
        }
        return s;
    }
};
