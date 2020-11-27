class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string str="";
        string ans="";
        int f,s;
        char fc,sc;
        if(A>B){
            f=A;
            s=B;
            fc='a';
            sc='b';
        }else{
            f=B;
            s=A;
            fc='b';
            sc='a';
        }

        for(int i=0;i<f;i++){
            str.push_back(fc);
        }
        int j=0;
        for(int i=0;i<s;i++){

            if(j<str.length())
            ans.push_back(str[j++]);
            if(j<str.length())
            ans.push_back(str[j++]);
            ans.push_back(sc);

        }
        while(j<str.length()){
            ans.push_back(str[j++]);
        }
        int k=0;
        while(ans.length()>=3 && ans[ans.length()-1]==ans[ans.length()-2] && ans[ans.length()-2] == ans[ans.length()-3]){
            ans.pop_back();
            k=0;
            while(k<ans.length()){
                if(ans[k]==fc){
                    if(k<=1){
                        ans=sc+ans;
                        break;
                    }else{
                        if(ans[k-1]==sc && ans[k-2]==sc){
                            k++;
                            continue;
                        }else{
                            ans=ans.substr(0,k)+sc+ans.substr(k,ans.length()-k);
                            break;
                        }
                    }
                }
                k++;
            }
        }
        return ans;
    }
};
