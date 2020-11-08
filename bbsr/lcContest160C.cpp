class Solution {
private:
    int maxi=0,n;
    vector<string> srr;

    bool isUnique(string s){
        int h[300]={0};
        for(int i=0;i<s.length();i++){
            if(h[s[i]]>0)
                return false;
            h[s[i]]=1;
        }
        return true;
    }

    void maxUniqueSubsequence(int index,int c,int* has){
        if(index==n){
            maxi=max(maxi,c);
            return;
        }
        maxUniqueSubsequence(index+1,c,has);
        string s= srr[index];
        if(isUnique(s)){
            int cnt=0;
            for(int i=0;i<s.length();i++){
                if(has[s[i]]==1){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                for(int i=0;i<s.length();i++){
                    has[s[i]]=1;
                }
                int l=s.length();
                maxUniqueSubsequence(index+1,c+l,has);
                for(int i=0;i<s.length();i++){
                    has[s[i]]=0;
                }
            }
        }
    }
public:
    int maxLength(vector<string>& arr) {
        n=arr.size();
        srr=arr;
        int has[300]={0};
        maxUniqueSubsequence(0,0,has);
        return maxi;
    }
};
