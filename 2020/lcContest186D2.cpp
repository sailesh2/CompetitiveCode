class Solution {
private:
    int NEG = -1000000000;


public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        pair<int,int> stk[n];
        int top=-1;
        int rear=-1;
        int maxi=NEG;
        for(int i=n-1;i>=n-k;i--){
            int v=nums[i];
            if(rear>-1){
                v=v+((stk[rear].first>0)?stk[rear].first:0);
            }
            while(top>-1 && top>=rear && stk[top].first<v){
                top--;
            }
            if(top<rear || top==-1){
                top=-1;
                rear=0;
            }

            stk[++top]=make_pair(v,i);
            maxi=max(maxi,v);
        }

        for(int i=n-k-1;i>=0;i--){
            int v = nums[i];

            if(rear>-1){
                v=v+((stk[rear].first>0)?stk[rear].first:0);
                if(stk[rear].second==i+k){
                    rear++;
                }
            }

            while(top>-1 && top>=rear && stk[top].first<v){
                top--;
            }
            if(top<rear || top==-1){
                top=-1;
                rear=0;
            }
            stk[++top]=make_pair(v,i);
            maxi=max(maxi,v);
        }

        return maxi;
    }
};
