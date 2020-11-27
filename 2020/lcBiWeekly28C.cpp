class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int minPrefix[n+1];
        for(int i=0;i<=n;i++){
            minPrefix[i]=0;
        }
        unordered_map<int,int> has;
        unordered_map<int,int>::iterator hasIt;
        int mini=1000000000;
        int s=0;
        has.insert(make_pair(0,0));
        for(int i=0;i<n;i++){
            s=s+arr[i];
            hasIt=has.find(s-target);
            if(hasIt!=has.end()){
                int ind = hasIt->second;
                if(minPrefix[ind]>0){
                    mini=min(mini,minPrefix[ind]+(i+1-ind));
                }

                minPrefix[i+1]=minPrefix[i]>0?min(minPrefix[i],i+1-ind):i+1-ind;
            }else{
                minPrefix[i+1]=minPrefix[i];
            }
            hasIt=has.find(s);
            if(hasIt!=has.end())
                has.erase(hasIt);
            has.insert(make_pair(s,i+1));
        }

        if(mini==1000000000)
            mini=-1;
        return mini;
    }
};
