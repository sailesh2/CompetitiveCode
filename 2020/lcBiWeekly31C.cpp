class Solution {
private:
    int pre[100005];
    int post[100005];

    void buildDistinctPre(string s){

        int d=0;
        int has[26]={0};
        for(int i=0;i<s.length();i++){
            if(has[s[i]-'a']==0){
                has[s[i]-'a']=1;
                d++;
            }
            pre[i]=d;
        }
    }


    void buildDistinctPost(string s){

        int d=0;
        int has[26]={0};
        for(int i=s.length()-1;i>=0;i--){
            if(has[s[i]-'a']==0){
                has[s[i]-'a']=1;
                d++;
            }
            post[i]=d;
        }
    }

    int splits(string s){
        int c=0;
        for(int i=0;i<s.length()-1;i++){
            if(pre[i]==post[i+1])
                c++;
        }
        return c;
    }
public:
    int numSplits(string s) {
        buildDistinctPre(s);
        buildDistinctPost(s);
        return splits(s);
    }
};
