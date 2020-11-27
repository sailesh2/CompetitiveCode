#include<bits/stdc++.h>

using namespace std;


long long int goodSubArrays(vector<long long int> nums, long long int n){
    long long int ans=0;
    map<long long int, long long int> mp;
    map<long long int, long long int>::iterator mpIt;
    long long int sm=0;
    mp.insert(make_pair(0,1));
    for(long long int i=0;i<n;i++){
        long long int c=0;
        sm=sm+nums[i];
        mpIt = mp.find(sm);
        if(mpIt!=mp.end()){
            c=mpIt->second;
            mp.erase(mpIt);
            ans=ans+c;
        }
        c++;
        mp.insert(make_pair(sm,c));
    }
    return ans;
}

long long int goodSubArrays(string s, long long int n){
    vector<long long int> nums;
    for(long long int i=0;i<n;i++){
        nums.push_back(s[i]-'0'-1);
    }
    return goodSubArrays(nums,n);
}

int main(){
    long long int t,n;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>n;
        string s;
        cin>>s;
        cout<<goodSubArrays(s,n)<<"\n";
    }
    return 0;
}
