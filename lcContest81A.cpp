class Solution {
public:
    vector<int> shortestToChar(string S, char c) {
        vector<int> ans;
        int left[S.length()];
        int right[S.length()];
        for(int i=0;i<S.length();i++){
            if(S[i]==c){
                left[i]=i;
            }else{
                if(i!=0)
                    left[i]=left[i-1];
                else
                    left[i]=1000000000;
            }
        }

        for(int i=S.length()-1;i>=0;i--){
            if(S[i]==c){
                right[i]=i;
            }else{
                if(i!=S.length()-1)
                    right[i]=right[i+1];
                else
                    right[i]=1000000000;
            }
        }

        for(int i=0;i<S.length();i++){
            ans.push_back(min(abs(i-left[i]),abs(i-right[i])));
        }
        return ans;
    }
};
