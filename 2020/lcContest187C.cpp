class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans=0;
        pair<int,int> maxStk[100005];
        pair<int,int> minStk[100005];

        int maxRear=-1;
        int minRear=-1;
        int maxTop = -1;
        int minTop = -1;
        int i=0;
        int j=0;
        for(;j<nums.size();j++){
            int v = nums[j];

            // fill max stack
            while(maxTop!=-1 && maxTop>=maxRear && maxStk[maxTop].first<v){
                maxTop--;
            }

            if(maxTop<maxRear || maxTop==-1){
                maxRear=0;
                maxTop=-1;
            }

            maxStk[++maxTop]=make_pair(v,j);


            // fill min stack
            while(minTop!=-1 && minTop>=minRear && minStk[minTop].first>v){
                minTop--;
            }

            if(minTop<minRear || minTop==-1){
                minRear=0;
                minTop=-1;
            }

            minStk[++minTop]=make_pair(v,j);

            if(maxStk[maxRear].first - minStk[minRear].first<=k){
                //cout<<maxStk[maxRear].first<<"\n";
                //cout<<minStk[minRear].first<<"\n";
                //cout<<i<<" "<<j<<"\n";
                ans=max(j-i+1,ans);
            }else{
                while(i<=j){
                    v = nums[i];

                    if(maxStk[maxRear].second==i){
                        maxRear++;
                    }

                    // reset
                    if(maxRear > maxTop){
                        maxRear=-1;
                        maxTop=-1;
                    }

                    if(minStk[minRear].second==i){
                        minRear++;
                    }

                    // reset
                    if(minRear > minTop){
                        minRear=-1;
                        minTop=-1;
                    }

                    i++;

                    if(maxTop==-1 || minTop==-1)
                        break;

                    if(maxStk[maxRear].first - minStk[minRear].first<=k){
                        break;
                    }

                }
            }
        }

        return ans;
    }
};
