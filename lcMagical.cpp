class Solution {
public:
    int magicalString(int n) {
        vector<int> magical;
        magical.push_back(1);
        magical.push_back(2);
        magical.push_back(2);

        vector<int> cumm;
        cumm.push_back(1);
        cumm.push_back(2);

        int i=2,cnt=0;
        int sum[1000005]={0};

        int ctr=0;
        while(magical.size()<=100005){
            cumm.push_back(magical[i]);

            if(magical[i]==1){
                magical.push_back(cnt+1);
            }else{
                magical.push_back(cnt+1);
                magical.push_back(cnt+1);
            }
            i++;
            cnt=1-cnt;
        }

        for(int i=0;i<magical.size();i++){
            if(magical[i]==1)
                ctr++;
            sum[i+1]=ctr;
        }
        return sum[n];
    }
};
