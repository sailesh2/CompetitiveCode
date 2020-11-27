class Solution {
private:

    bool isBloom(vector<int>& bloomDay, int d, int n, int m, int k){
        int arr[n];
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=d){
                arr[i]=1;
            }else{
                arr[i]=0;
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(c==k){
                m--;
                c=0;
            }
            if(arr[i]==1){
                c++;
            }else{
                c=0;
            }
        }
        if(c==k)
            m--;

        return m<=0;
    }

    int minBloomDay(vector<int>& bloomDay, int n, int m, int k){
        int ctr=1;
        int save=-1;
        int save2=-1;

        int maxDay = 0;
        for(int i=0;i<n;i++)
            maxDay=max(maxDay,bloomDay[i]);

        while(1){
            while(save+ctr<=maxDay && !isBloom(bloomDay, save+ctr, n, m ,k)){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }

        return save+1;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*k>n)
            return -1;

        return minBloomDay(bloomDay, n, m , k);
    }
};
