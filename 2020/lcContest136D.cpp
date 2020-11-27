class Solution {
private:
    long long int mod=1000000000000009;
    long long int power[100005];

    void storePower(int n){
        long long int p=1;
        power[0]=p;
        for(int i=1;i<=n;i++){
            p=(p*31)%mod;
            power[i]=p;
        }
    }

    bool isDuplicatePresent(string s, int len){
        if(len==0)
            return true;
        set<long long int> mp;
        long long int has=0;
        for(int i=0;i<len;i++){
            has=((has*31)%mod+(s[i]-'a'))%mod;
        }
        mp.insert(has);
        for(int i=len;i<s.length();i++){
            long long int v=(power[len-1]*(s[i-len]-'a'))%mod;
            has=(( ( (has-v+mod)%mod)*(long long int)31)%mod +(s[i]-'a'))%mod;

            if(mp.count(has)>0)
                return true;
            mp.insert(has);
        }
        return false;
    }

    int getDupPos(string s, int len){
        set<long long int> mp;
        long long int has=0;
        for(int i=0;i<len;i++){
            has=((has*31)%mod+(s[i]-'a'))%mod;
        }
        mp.insert(has);
        for(int i=len;i<s.length();i++){
            long long int v=(power[len-1]*(s[i-len]-'a'))%mod;
            has=(( ((has-v+mod)%mod)*(long long int)31)%mod +(s[i]-'a'))%mod;
            if(mp.count(has)>0)
            {
                return i-len+1;
            }
            mp.insert(has);
        }
        return 0;
    }

    long long int binSearWithSteps(string s){
        int ctr=1;
        int save=-1;
        int save2=-1;
        int k=s.length();

        while(1){
            while(save+ctr<k && isDuplicatePresent(s,ctr+save)){
                save2=save+ctr;
                ctr=ctr*2;
            }
            if(save==save2){
                break;
            }
            save=save2;
            ctr=1;
        }
        return save;
    }

    string getDuplicate(string s, int len){
        string dupl="";
        if(len==-1)
            return dupl;
        int pos=getDupPos(s,len);
        for(int i=pos;i<pos+len;i++){
            dupl.push_back(s[i]);
        }
        return dupl;
    }
public:
    string longestDupSubstring(string s) {
        storePower(s.length());
        return getDuplicate(s, binSearWithSteps(s));
    }
};
