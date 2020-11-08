class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int maxTurb=1,turb=0,cnt=0;
        for(int i=0;i<A.size()-1;i++){
            if(cnt==0){
                if(A[i]<A[i+1]){
                    turb++;
                    maxTurb=max(maxTurb,turb+1);
                }else{
                    while(i<A.size()-1 && A[i]==A[i+1]){
                        i++;
                    }
                    maxTurb=max(maxTurb,turb+1);

                    turb=1;
                    if(A[i]>A[i+1])
                    cnt=1;
                }
            }else{
                if(A[i]>A[i+1]){
                    turb++;
                    maxTurb=max(maxTurb,turb+1);
                }else{

                    while(i<A.size()-1 && A[i]==A[i+1]){
                        i++;
                    }
                    maxTurb=max(maxTurb,turb+1);
                    turb=1;
                    if(A[i]<A[i+1])
                    cnt=0;
                }
            }
            cnt=1-cnt;
        }
        return maxTurb;
    }
};
