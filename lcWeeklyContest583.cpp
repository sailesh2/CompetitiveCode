class Solution {
public:
    string minWindow(string S, string T) {
        int mini=S.length()+1;
        int st,en,next=0,savest,saveen,j;
        while(next<S.length()){
            st=-1;
            en=-1;
            j=0;
            for(int i=next;i<S.length();i++){
                if(S[i]==T[j]){
                    if(j==0){
                        st=i;
                    }
                    if(j==T.length()-1){
                        en=i;
                        break;
                    }
                    j++;
                }
            }
            if(en==-1)
                break;
            if(en-st+1<mini){
                mini=en-st+1;
                savest=st;
                saveen=en;
            }
            next=st+1;
        }
        string w="";
        for(int i=savest;i<=saveen;i++){
            w=w+S[i];
        }
        return w;
    }
};
