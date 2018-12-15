#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        int f,n;
        n=heights.size();
        for(int i=0;i<V;i++){
            f=K;
            for(int j=0;j<heights.size();j++){
                cout<<heights[j]<<" ";
            }
            cout<<"\n";
            while(1){
                if(f>0 && heights[f-1]<heights[f]){

                    f--;
                }else if(f<n-1 && heights[f+1]<heights[f]){

                    f++;
                }else{
                    heights[f]++;
                    break;
                }
            }
        }
        return heights;
    }
};

int main(){
    Solution sol;
    int V=5;
    vector<int> heights;
    heights.push_back(1);
    heights.push_back(2);
    heights.push_back(3);
    heights.push_back(4);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(2);
    heights.push_back(3);
    heights.push_back(4);
    heights.push_back(3);
    heights.push_back(2);
    heights.push_back(1);
    sol.pourWater(heights,V,V);
}
