class Solution {
public:
    string reformat(string s) {
        vector<int> alph, num;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                num.push_back(s[i]);
            }else{
                alph.push_back(s[i]);
            }
        }

        string ans="";
        int al=alph.size();
        int nl=num.size();
        if(abs(al-nl)<=1){
            if(al<nl){
                int i=0;
                int j=0;
                int ctr=0;
                while(i<al){
                    if(ctr%2==0){
                        ans.push_back(num[j]);
                        j++;
                    }else{
                        ans.push_back(alph[i]);
                        i++;
                    }
                    ctr=1-ctr;
                }
                if(j<nl)
                    ans.push_back(num[i]);
            }else{
                int i=0;
                int j=0;
                int ctr=0;
                while(j<nl){
                    if(ctr%2!=0){
                        ans.push_back(num[j]);
                        j++;
                    }else{
                        ans.push_back(alph[i]);
                        i++;
                    }
                    ctr=1-ctr;
                }
                if(i<al)
                    ans.push_back(alph[i]);
            }
        }
        return ans;
    }
};
