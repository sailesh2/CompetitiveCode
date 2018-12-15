#include<bits/stdc++.h>

using namespace std;


class Solution {

private:
    pair<int,pair<int,int> > dp[50][50][2];
    void clearDP(){
        pair<int,pair<int,int> > p =make_pair(-1,make_pair(-1,-1));
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                dp[i][j][0]=p;
                dp[i][j][1]=p;
            }
        }
    }

    bool isEmptyDP(pair<int,pair<int,int> > p){
        return p.first==-1;
    }
public:
    int maxCoins(vector<int>& nums) {
        clearDP();
        pair<int,pair<int,int> > p = maxCoinsDP(nums,0,nums.size()-1,0);
        return p.first;
    }

    pair<int,pair<int,int> > maxCoinsDP(vector<int>& nums,int start, int endI,int cnt) {
       // cout<<start<<" "<<endI<<"\n";
        if(start<0 || endI>=nums.size() || start>endI){
            return make_pair(0,make_pair(0,0));
        }

        int a=0,maxi=-10000000,save,save2;
        pair<int,pair<int,int> > pl,pr;
        for(int i=start;i<=endI;i++){

           // cout<<start<<" " <<i<<" "<<endI<<"\n";
            //if(i-1>=0 && !isEmptyDP(dp[start][i-1][cnt]))
            //    pl=dp[start][i-1][cnt];
            //else
                pl=maxCoinsDP(nums,start,i-1,0);

            //if(i+1<nums.size() && !isEmptyDP(dp[i+1][endI][cnt]))
              //  pr=dp[i+1][endI][cnt];
            //else
                pr=maxCoinsDP(nums,i+1,endI,1);
            //cout<<pl.second.first<<pl.second.second<<"\n";
            a=pl.first+((pl.second).first*(pl.second).second * nums[i]);
            a=a+pr.first+((pr.second).first*(pr.second).second * nums[i]);
            if(start==0 && endI==nums.size()-1){
                a=a+(pl.second).first*nums[i]+(pr.second).first*nums[i]+nums[i];
            }
            //cout<<start<<" " <<i<<" "<<endI<<" "<<a<<"\n";

            if(a>maxi){
                maxi=a;
                save=i;
                if(cnt==0){
                    save2=(pr.second).first;
                } else{
                    save2=(pl.second).first;
                }
            } else if(a==maxi){
                if(cnt==0 && (pr.second).first>save2){
                    save=i;
                    save2=(pr.second).first;
                } else if(cnt==1 && (pl.second).first>save2){
                    save2=(pl.second).first;
                    save=i;
                }
            }
        }
        dp[start][endI][cnt]=make_pair(maxi,make_pair(nums[save],save2));
        return dp[start][endI][cnt];
    }
};

int main(){
    Solution solution;
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(8);
    cout<<solution.maxCoins(v);
    return 0;
}
