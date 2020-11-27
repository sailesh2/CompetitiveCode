class Solution {
private:

    vector<int> rev(vector<int> arr){
        vector<int> revers;
        for(int i=arr.size()-1;i>=0;i--){
            revers.push_back(arr[i]);
        }
        return revers;
    }

    vector<int> pad(vector<int> arr, int newSize){
        vector<int> padded;
        int padding = newSize - arr.size();
        for(int i=0;i<padding;i++){
            padded.push_back(0);
        }
        for(int i=0;i<arr.size();i++){
            padded.push_back(arr[i]);
        }
        return padded;
    }

    vector<int> add(vector<int> arr1, vector<int> arr2){
        if(arr1.size()>arr2.size()){
            arr2=pad(arr2,arr1.size());
        }
        int n=arr1.size();
        int ctr=0,c=0;
        vector<int> res;
        for(int i=n-1;i>=0;i--){
            if(ctr==0){
                res.push_back((c+arr1[i]+arr2[i])%2);
                c=(c+arr[i]+arr[2])/2;
            }else{
                if(arr1[i]+c<arr2[i]){
                    res.push_back(0);
                    c=-1;
                }else{
                    res.push_back((arr1[i]+c-arr2[i])%2);
                    c=(arr1[i]+c-arr2[i])/2;
                }
            }
            ctr=1-ctr;
        }

        return rev(res);
    }
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> maxA,minA;

        if(arr1.size()>arr2.size()){
            maxA=arr1;
            minA=arr2;
        }else if(arr1.size()<arr2.size()){
            maxA=arr2;
            minA=arr1;
        }else{
            maxA=arr1;
            minA=arr2;
            for(int i=0;i<arr1.size();i++){
                if(arr1[i]!=arr2[i]){
                    if(arr1[i]==1){
                        maxA=arr1;
                        minA=arr2;
                    }else{
                        maxA=arr2;
                        minA=arr1;
                    }
                }
            }
        }
        return add(maxA,minA);
    }
};
