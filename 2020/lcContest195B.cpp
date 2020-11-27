class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int modCnt[100005]={0};
        for(int i=0;i<arr.size();i++){

            modCnt[(k+arr[i]%k)%k]++;
        }

        for(int i=0;i<k;i++){
            if(i==0){
                if(modCnt[i]%2!=0)
                    return false;
            }else{
                if(modCnt[i]!=modCnt[k-i])
                   return false;
            }
        }

        return true;
    }
};
