class Solution {
public:
    int numSteps(string s) {
        int ctr=0;

        int save=-1;
        int n = s.length();
        int pre[n];
        int cnt=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                save=i;
            }
            pre[i]=save;
        }
        for(int i=s.length()-1;i>0;i--){
            if(s[i]=='0'){
                ctr++;
            }else{
                ctr++;
                ctr=ctr+(i-pre[i]);
                i=pre[i];
                if(i==-1)
                    break;
                pre[i]=pre[i-1];
                //cout<<i<<"\n";
                s[i]='1';
                i++;
            }
        }

        return ctr;
    }
};
