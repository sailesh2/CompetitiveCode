class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int col[n][m];

        for(int i=0;i<m;i++){
            int sm=0;
            for(int j=0;j<n;j++){
                sm=sm+mat[j][i];
                col[j][i]=sm;
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ctr=0;
                for(int k=0;k<m;k++){
                    if(i-1>=0){
                        if( (col[j][k]-col[i-1][k]) == (j-i+1) ){
                            ctr++;
                        }else{
                            ans=ans+(ctr*(ctr+1))/2;
                            ctr=0;
                        }
                    }else{
                        if( col[j][k] == (j+1)){
                            ctr++;
                        }else{
                            ans=ans+(ctr*(ctr+1))/2;
                            ctr=0;
                        }
                    }
                }
               ans=ans+(ctr*(ctr+1))/2;

            }
        }

        return ans;
    }
};
