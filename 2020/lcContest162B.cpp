class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n=colsum.size();
        vector<vector<int> > grid;
        vector<int> v;

        for(int i=0;i<n;i++){
            v.push_back(0);
        }
        grid.push_back(v);
        grid.push_back(v);

        for(int i=0;i<n;i++){
            if(colsum[i]==2){
                grid[0][i]=1;
                grid[1][i]=1;
                upper--;
                lower--;
            }
        }

        for(int i=0;i<n;i++){
            if(colsum[i]==1){
                if(lower>0){
                    grid[1][i]=1;
                    lower--;
                }else{
                    grid[0][i]=1;
                    upper--;
                }
            }
        }

        vector<vector<int> > emptyV;

        if(upper==0 && lower==0)
        return grid;
        else
        return emptyV;
    }
};
