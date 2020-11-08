class Solution {
private:
    vector<int> getDig(int start, int n){
        vector<int> dig;
        while(start>0){
            dig.push_back(start%2);
            start=start/2;
        }
        int l=dig.size();
        for(int i=0;i<n-l;i++){
            dig.push_back(0);
        }

        vector<int> rev;
        for(int i=dig.size()-1;i>=0;i--){
            rev.push_back(dig[i]);
        }
        return rev;
    }

    int convertToNum(vector<int> dig){
        int v=0;
        for(int i=0;i<dig.size();i++){
            v=v*2+dig[i];
        }
        return v;
    }
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        vector<int> dig = getDig(start,n);

        set<int> has;
        ans.push_back(start);
        has.insert(start);
        while(1){
            int cnt=0;
            for(int i=0;i<dig.size();i++){
                dig[i]=1-dig[i];
                int v=convertToNum(dig);
                if(has.count(v)==0){
                    has.insert(v);
                    ans.push_back(v);
                    cnt=1;
                    break;
                }
                dig[i]=1-dig[i];
            }
            if(cnt==0)
                break;
        }
        return ans;
    }
};
