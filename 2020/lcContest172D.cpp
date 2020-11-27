class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        int taps[n+1];
        for(int i=0;i<n+1;i++)
            taps[i]=-1;
        for(int i=0;i<n+1;i++){
            for(int j=i-ranges[i];j<=i+ranges[i];j++){
                if(j>=0 && j<n+1){
                    taps[j]=max(taps[j],i+ranges[i]);
                }
            }
        }

        int st=0;
        int ctr=0;
        while(st<n){
            int prev=st;
            st=taps[st];
            if(st<=prev){
                return -1;
            }
            ctr++;
        }
        return ctr;
    }
};
