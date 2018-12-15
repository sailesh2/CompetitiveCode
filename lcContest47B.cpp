class Solution {
public:
    vector<int> partitionLabels(string S) {
        int l=0,cnt;
        vector<int> ans;
        while(l<s.length()){
            for(int i=l;i<s.length();i++){
                int has[300]={0};
                for(int j=l;j<=i;j++){
                    has[(int)s[j]]=1;
                }
                cnt=0;
                for(int j=i+1;j<s.length();j++){
                    if(has[(int)s[j]]==1){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==0){
                    l=i+1;
                    ans.push_back(l-i+1);
                    break;
                }
            }
        }
        return ans;
    }
};
