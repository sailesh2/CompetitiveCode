class Solution {
public:
    string orderlyQueue(string s, int k) {

        string ans=s;
        int n=s.length();
        while(1){
            int save=-1;
            for(int i=0;i<k;i++){
                if(i+1<n && s[i]<s[i+1]){
                    save=i;
                    break;
                }
            }

            if(save==-1)
                break;

            char saved = s[save];
            for(int i=save;i<n;i++)
                s[i]=s[i+1];
            s[n-1]=saved;
        }

        return s;
    }
};
