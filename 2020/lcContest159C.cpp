class Solution {
private:
    int Q=0,W=0,E=0,R=0;
    int req;

    void setup(string s){
        req=(s.length())/4;

        for(int i=0;i<s.length();i++){
            if(s[i]=='Q'){
                Q++;
            }
            if(s[i]=='W'){
                W++;
            }
            if(s[i]=='E'){
                E++;
            }
            if(s[i]=='R'){
                R++;
            }
        }
    }

    bool possible(int q,int w,int e, int r){
        bool a=(Q-q)<=req && (W-w)<=req && (E-e)<=req && (R-r)<=req;
        int totReq=req-(Q-q) + req-(W-w) + req-(E-e) + req-(R-r);
        return a && totReq==(q+w+e+r);
    }

    bool canBeBalanced(int subSize,string s){
        int q=0,w=0,e=0,r=0;
        for(int i=0;i<subSize;i++){
            if(s[i]=='Q'){
                q++;
            }
            if(s[i]=='W'){
                w++;
            }
            if(s[i]=='E'){
                e++;
            }
            if(s[i]=='R'){
                r++;
            }

            if(possible(q,w,e,r))
                return true;
        }

        for(int i=subSize;i<s.length();i++){
            int last = i-subSize;
            if(s[last]=='Q'){
                q--;
            }
            if(s[last]=='W'){
                w--;
            }
            if(s[last]=='E'){
                e--;
            }
            if(s[last]=='R'){
                r--;
            }

            if(s[i]=='Q'){
                q++;
            }
            if(s[i]=='W'){
                w++;
            }
            if(s[i]=='E'){
                e++;
            }
            if(s[i]=='R'){
                r++;
            }

            if(possible(q,w,e,r))
                return true;
        }

        return false;
    }

    int minBalanceString(string s){
        int l=s.length();
        int ctr=1;
        int save=-1;
        int save2=-1;

        while(1){
            while(save+ctr<=l && !canBeBalanced(save+ctr,s)){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save+1;
    }
public:
    int balancedString(string s) {
        setup(s);
        return minBalanceString(s);
    }
};
