#include<bits/stdc++.h>

using namespace std;


class HillClimber{
public:
  int longest(vector<int> arr){
      int maxi=0;
      int ctr=0;
      for(int i=1;i<arr.size();i++){
        if(arr[i]>arr[i-1]){
            ctr++;
            maxi=max(maxi,ctr);
        }else{
            ctr=0;
        }
      }
      return maxi;
  }
};
