class Solution {
private:
    vector<int> digits;

    void createSeqDigits(){
        for(int i=1;i<10;i++){
            for(int j=1;j<10;j++){
                if(j+i-1>=10)
                    break;
                int v=0;
                for(int k=0;k<i;k++){
                    v=v*10+(j+k);
                    //cout<<j+k<<"\n";
                }
                //cout<<v<<"\n";
                if(v!=0)
                digits.push_back(v);
            }
        }
        sort(digits.begin(),digits.end());
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        createSeqDigits();
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            if(digits[i]>=low && digits[i]<=high)
                ans.push_back(digits[i]);
        }
        return ans;
    }
};
