class Solution {
private:
    map<pair<int,int>,int> dp;
    map<pair<int,int>,int>::iterator dpIt;

    int n;
    vector<int> arr;
    int longArith(int index, int diff){

        int maxi=0;
        if(dif==-1){

            for(int i=index+1;i<n;i++){
                dpIt = dp.find(make_pair(i,arr[i]-arr[index]));
                if(dpIt == dp.end())
                    maxi=max(maxi,longArith(i,arr[i]-arr[index])+1);
                else
                    maxi=max(maxi,(dpIt->second)+1);

            }
        }else{
            for(iunt i=index+1;i<n;i++){
                if(arr[i]-arr[index]==diff){
                    if(dpIt == dp.end())
                        maxi=max(maxi,longArith(i,diff)+1);
                    else
                        maxi=max(maxi,(dpIt->second)+1);

                }
            }
        }

        dp.insert(make_pair(make_pair(index,diff),maxi));
        return maxi;
    }

    int longArithSeq(){
        int maxiV=0;
        for(int i=0;i<n;i++){
            maxiV=max(maxiV,longArith(i,-1));
        }
        return maxiV;
    }
public:
    int longestArithSeqLength(vector<int>& A) {
        n=A.size();
        arr=A;
        return longArithSeq();
    }
};
