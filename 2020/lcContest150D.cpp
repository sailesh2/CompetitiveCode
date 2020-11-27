class Solution {
public:
    string lastSubstring(string s) {
        int n=s.length();
        char maxL = getMaxLetter(s);
        vector<int> maxPos = getMaxLetterPos(s, maxL);
        int has[500005]={0};
        int ctr=0,start=0;
        while(start!=-1){
            int maxC='a';
            for(int i=0;i<maxPos.size();i++){
                int pos = maxPos[i];
                if(has[pos]==0){
                if(pos+ctr<n && has[pos+ctr]==0){
                    maxC=max(maxC,s[pos+ctr]);
                }else{
                    has[pos]=1;
                }
                }
            }
            strat=-1;
            for(int i=0;i<maxPos.size();i++){
                int pos = maxPos[i];
                if(has[pos]==0){
                if(pos+ctr<n && has[pos+ctr]==0 && (int)s[pos+ctr]==maxC){
                    if(cnt==0){
                        cnt=1;
                        start=pos;
                    }
                }else{
                    has[pos+ctr]=1;
                }
                }
            }
            ctr++;
        }
    }
};
