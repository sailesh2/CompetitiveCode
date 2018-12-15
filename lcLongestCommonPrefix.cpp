class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int save=0,l;
        string matched="";
        for(int i=0;i<strs.size();i++){
            l=strs[i].length();
            if(i==0){
                save=l-1;
            }else{
                //cout<<
               if(l-1<save){
                   save=l-1;
               }
            }
            //cout<<save<<" ";
            for(int j=0;j<l;j++){

                if(i==0){
                    matched=matched+strs[i][j];
                }else{
                    if(j<=save){
                        if(strs[i][j]!=matched[j]){
                            save=j-1;
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
        }
        string s="";
        for(int i=0;i<=save;i++){
            s=s+matched[i];
        }
        return s;
    }
};
