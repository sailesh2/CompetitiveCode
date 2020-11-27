class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int k=arr.size();
        k=k/4;
        int st[100005]={0};
        for(int i=0;i<arr.size();i++){
            st[arr[i]]++;
            if(st[arr[i]]>k){
                return arr[i];
            }
        }
        return 0;
    }
};
