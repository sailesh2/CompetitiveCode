class Solution {
public:
    string orderlyQueue(string s, int k) {

        string ans=s;
        int n=s.length();
        int save=-1;
        int mini;

        for(int j=0;j<k-1;j++{
            for(int i=j;i<n;i++){
                if(i==j){
                    mini=s[i];
                    save=i;
                }else{
                if(s[i]<mini){
                    mini=s[i];
                    save=i;
                }
                }
            }
            ans="";
            for(int i=0;i<j;i++)
                ans.push_back(s[i]);
            for(int i=save;i<n;i++){
                ans.push_back(s[i]);
            }
            for(int i=j;i<save;i++){
                ans.push_back(s[i]);
            }
            s=ans;
        }

        for(int i=k;i<n;i++){
            if(i==k){
                mini=s[i];
            }else{
                if(s[i]<mini){
                    mini=s[i];
                    save=i;
                }
            }
        }

        for(int i=k;i<n;i++){
            if(s[i]==mini){
                v.push_back(i);
            }
        }

        for(int i=0;i<v.size();i++){
            save=v[i];
            ans="";
            for(int i=0;i<k;i++)
                ans.push_back(s[i]);
            for(int i=save;i<n;i++){
                ans.push_back(s[i]);
            }
            for(int i=j;i<save;i++){
                ans.push_back(s[i]);
            }
            last.push_back(ans);
        }

        sort(last.begin(),last.end());
        return last;
    }
};
