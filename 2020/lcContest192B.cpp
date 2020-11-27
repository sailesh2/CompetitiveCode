int median;

bool customSort(int a, int b){
    if(abs(a-median)==abs(b-median))
        return a>b;
    return abs(a-median)>abs(b-median);
}

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int st=arr.size();
        if(st%2!=0)
            median = arr[st/2];
        else
            median=arr[st/2-1];

        sort(arr.begin(),arr.end(),customSort);
        vector<int> ans;
        for(int i=0;i<min(st,k);i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
