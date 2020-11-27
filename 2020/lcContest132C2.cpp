class Solution {
private:
    map<pair<int,int>,int> dp;
    map<pair<int,int>,int>::iterator dpIt;
    map<pair<int,int>,int>::iterator dpIt2;

    int n;
    vector<int> arr;
    int maxi=0;
    void longArith(){

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                int diff=arr[j]-arr[i];
                dpIt=dp.find(make_pair(j,diff));
                if(dpIt==dp.end()){
                    if(dp.find(make_pair(i,diff))==dp.end()){
                        dp.insert(make_pair(make_pair(i,diff),1));
                        maxi=max(maxi,1);
                    }else{
                        dpIt2=dp.find(make_pair(i,diff));
                        if(dpIt2->second<1){
                            maxi=max(maxi,1);
                            dp.erase(dpIt2);
                            dp.insert(make_pair(make_pair(i,diff),1));

                        }
                    }
                }else{
                    if(dp.find(make_pair(i,diff))==dp.end()){
                        maxi=max(maxi,1+(dpIt->second));
                        dp.insert(make_pair(make_pair(i,diff),1+(dpIt->second)));
                    }else{
                        dpIt2=dp.find(make_pair(i,diff));
                        if(dpIt2->second<(1+(dpIt->second))){
                            maxi=max(maxi,1+(dpIt->second));
                            dp.erase(dpIt2);
                            dp.insert(make_pair(make_pair(i,diff),1+(dpIt->second)));

                        }
                    }
                }
            }
        }
    }
public:
    int longestArithSeqLength(vector<int>& A) {
        n=A.size();
        arr=A;
        longArith();
        return maxi+1;
    }
};
