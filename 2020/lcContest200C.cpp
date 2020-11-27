class Solution {
private:

	bool doesRequireSwap(vector<int> row, int zeros){
		int n = row.size();
		n--;
        for(int i=0;i<zeros;i++){
            if(row[n]!=0)
                return true;
            n--;
        }
        return false;
}

bool canSwap(vector<int> row, int zeros){
	return !doesRequireSwap(row,zeros);
}
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        int swaps=0;

        for(int i=0;i<n;i++){
            vector<int> row=grid[i];
            if(doesRequireSwap(row,n-i-1)){
                int cnt=0;

                for(int j=i+1;j<n;j++){
                    vector<int> swapRow = grid[j];
                    if(canSwap(swapRow,n-i-1)){
                        for(int k=j;k>i;k--){
                            grid[k]=grid[k-1];
                        }
                        grid[i]=swapRow;
                        swaps=swaps+j-i;
                        cnt=1;
                        break;
                    }
                }
            if(cnt==0)
                return -1;
            }
        }

        return swaps;
    }
};
