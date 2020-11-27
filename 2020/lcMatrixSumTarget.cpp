class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();

        int dpc[n][m];
        int ctr=0;

        for(int i=0;i<m;i++){
            int c=0;
            for(int j=0;j<n;j++){
                c=c+matrix[j][i];
                dpc[j][i]=c;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int c=0;
                unordered_map<int,int> mp;
                unordered_map<int,int>::iterator mpIt;
                mp.insert(make_pair(0,1));
                for(int k=0;k<m;k++){
                    c=c+((i-1>=0)?dpc[j][k]-dpc[i-1][k]:dpc[j][k]);
                    mpIt = mp.find(c-target);
                    int v=0;
                    if(mpIt!=mp.end()){
                        v=mpIt->second;
                    }
                    ctr=ctr+v;
                    mpIt = mp.find(c);
                    v=0;
                    if(mpIt!=mp.end()){
                        v=mpIt->second;
                        mp.erase(mpIt);
                    }
                    v++;
                    mp.insert(make_pair(c,v));
                }
            }
        }

        return ctr;
    }
};
