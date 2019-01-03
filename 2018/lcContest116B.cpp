class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n=A.size();
        if(n<=1)
            return 0;
        int i=0,j=n-1;
        int maxBack[n];
        for(int k=n-1;k>=0;k--){
            if(k==n-1){
                maxBack[k]=A[k];
            }else{
                maxBack[k]=max(maxBack[k+1],A[k]);
            }
        }
        while(i<j){
            if(A[i]>maxBack[j]){
                j--;
            }else{
                break;
            }
        }
            int save=A[i];
            int maxi=j-i;
            if(i>=j)
                    j=i+1;
            while(i<j && i<n && j<n){
                while(i<n){
                    if(A[i]<save){
                        save=A[i];
                        break;
                    }
                    i++;
                }
                if(i>=j)
                    j=i+1;
                while(j<n){
                    if(save<=maxBack[j]){
                        maxi=max(maxi,j-i);
                        j++;
                    }else{
                        break;
                    }
                }
            }
            return maxi;

    }
};
