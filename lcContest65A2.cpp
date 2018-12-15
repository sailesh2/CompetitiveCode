#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<pair<int,long long int>,int> dp;
    map<pair<int,long long int>,int>::iterator dpIt;
    set<int> has;
    int reachNumberDP(int ind,long long int sum,int target){
        cout<<ind<<" "<<sum<<"\n";


        if(sum>target || sum<-1*target){
            return -1;
        }else if(sum==target){
            return 0;
        }
        int a=-1,b=-1;
        if(has.count(sum+ind)==0){
            has.insert(sum+ind);
            dpIt=dp.find(make_pair(ind+1,sum+ind));
            cout<<"a\n";
            if(dpIt==dp.end())
                a=reachNumberDP(ind+1,sum+ind,target);
            else
                a=dpIt->second;

            has.erase(sum+ind);
        }
        if(has.count(sum-ind)==0){
            has.insert(sum-ind);
            dpIt=dp.find(make_pair(ind+1,sum-ind));
            if(dpIt==dp.end())
                b=reachNumberDP(ind+1,sum-ind,target);
            else
                b=dpIt->second;
            has.erase(sum-ind);
        }
        int c;
        if(a==-1 && b==-1)
            c=-1;
        else if(a==-1)
            c=b+1;
        else if(b==-1)
            c=a+1;
        else
            c=min(a,b)+1;
        dp.insert(make_pair(make_pair(ind,sum),c));
        return c;
    }
public:
    int reachNumber(int target) {
        has.insert(0);
        return reachNumberDP(1,0,abs(target));
    }
};

int main(){
    Solution sol;
    cout<<sol.reachNumber(-1000000000);
    return 0;
}
