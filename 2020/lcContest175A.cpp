class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> has;

        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0 && has.count(arr[i]/2)>0)
                return true;
            if(has.count(2*arr[i])>0)
                return true;
            has.insert(arr[i]);
        }
        return false;
    }
};
