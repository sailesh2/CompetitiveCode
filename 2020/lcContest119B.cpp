class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int a,b,c,cnt=0;
        for(int j=0;j<A.size();j++){
            a = A[A.size()-j-1];
            b = A[A.size()-j-2];
            cnt=0;
            for(int i=A.size()-j-3;i>=0;i--){
                c=A[i];
                if(a+b>c && a+c>b && b+c>a){
                    cnt=1;
                    break;
                }
            }
            if(cnt==1)
                break;
        }
        if(cnt==0)
            return 0;
        else
            return a+b+c;
    }
};
