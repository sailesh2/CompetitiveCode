class Solution {
private:
    int pre[10004];

    void storePrefix(vector<int>& arr){
        int s=0;
        for(int i=0;i<arr.size();i++){
            s=s+arr[i];
            pre[i]=s;
        }
    }

    int bin(int cost,int n, vector<int>& arr){
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<n && arr[save+ctr]<=cost){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save;
    }

public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        storePrefix(arr);
        int n = arr.size();
        int mini=1000000009;
        int save=0;
        for(int i=0;i<=target;i++){
            int ind = bin(i,n,arr);
            int v = (ind>=0)?pre[ind]+(n-ind-1)*i:n*i;
            if(abs(v-target)<mini){
                mini=abs(v-target);
                save=i;
            }
        }
        return save;
    }
};
