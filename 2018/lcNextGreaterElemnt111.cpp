    bool comparator(int a, int b){
        return a>b;
    }

class Solution {

public:
    int nextGreaterElement(int n) {
        vector<int> arr;
        while(n>0){
            arr.push_back(n%10);
            n=n/10;
        }
        int cnt=0,temp;
        for(int i=1;i<arr.size();i++){
            if(arr[i]<arr[i-1]){
                for(int j=i-1;j>=0;j--){
                    if(arr[j]<=arr[i]){
                        temp=arr[i];
                        arr[i]=arr[j+1];
                        arr[j+1]=temp;
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    temp=arr[i];
                    arr[i]=arr[0];
                    arr[0]=temp;
                }
                cnt=1;
                sort(arr.begin(), arr.begin()+i,comparator);
                break;
            }
        }
        if(cnt==0)
            return -1;
        long long int num=0;
        for(int i=arr.size()-1;i>=0;i--){
            num=num*10+arr[i];
        }
        if(num>1000000000)
            return -1;

        return num;
    }
};
