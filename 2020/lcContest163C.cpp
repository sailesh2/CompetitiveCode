class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> ones,twos;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0)
                s=s+nums[i];
            else if(nums[i]%3==1)
                ones.push_back(nums[i]);
            else
                twos.push_back(nums[i]);
        }

        sort(ones.begin(),ones.end());
        sort(twos.begin(),twos.end());

        int o=ones.size()-1;
        int t=twos.size()-1;
        int so,to,sto;
        while(o>=0 && t>=0){
            so=-1;
            to=-1;
            if(o-2>=0){
                so=ones[o]+ones[o-1]+ones[o-2];
            }
            if(t-2>=0){
                st=twos[t]+twos[t-1]+twos[t-2];
            }
            sto=ones[o]+twos[t];
            if(so>to && so>sto){
                s=s+so;
                o=o-3;
            }else if(to>so && to>sto){
                s=s+to;
                t=t-3;
            }else{
                s=s+sto;
                o--;
                t--;
            }
        }

        while(o-2>=0){
                s=s+ones[o]+ones[o-1]+ones[o-2];
                o=o-3;
        }

        while(t-2>=0){
                s=s+twos[t]+twos[t-1]+twos[t-2];
                t=t-3;
        }

        return s;

    }
};
