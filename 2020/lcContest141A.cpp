class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> dupArr;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                dupArr.push_back(0);
                dupArr.push_back(0);
            }else{
                dupArr.push_back(arr[i]);
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=dupArr[i];
        }
    }
};
