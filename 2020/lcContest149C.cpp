class Solution {
private:
    int getMaxLength(string text, char l){
        int has[20005]={0};
        int cnt=0;
        for(int i=text.length()-1;i>=0;i--){
            if(text[i]==l){
                cnt=1;
            }
            has[i]=cnt;
        }

        int maxi=0,save=0,c=0;
        for(int i=0;i<text.length();i++){
            if(text[i]==l){
                c++;
            }else{
                if(c>0){
                    maxi=max(maxi,save+c+has[i]);
                    save=c;
                }else{
                    save=0;
                }
                c=0;
            }
        }

        maxi=max(maxi,save+c);
        return maxi;
    }

    string rev(string text){

        string r="";
        for(int i=text.length()-1;i>=0;i--)
            r.push_back(text[i]);
        return r;
    }
public:
    int maxRepOpt1(string text) {
        int maxi=0;
        for(char c='a';c<='z';c++){
            maxi=max(maxi,getMaxLength(text,c));

            maxi=max(maxi,getMaxLength(rev(text),c));
        }

        return maxi;
    }
};
