class Solution {
private:
    set<string> mp;
    set<string>::iterator mpIt;


    string convertToStr(int v){
        string s="";
        while(v>0){
            s.push_back((char)(v%10+48));
            v=v/10;
        }
        string srev="";
        for(int i=s.length()-1;i>=0;i--)
            srev.push_back(s[i]);
        return srev;
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;

        for(int i=0;i<names.size();i++){
            string s= names[i];

            mpIt = mp.find(s);
            if(mpIt!=mp.end()){
                for(int v=1;v<names.size();v++){
                        string s2=s;
                        s2.push_back('(');
                        string s3=convertToStr(v);
                        for(int j=0;j<s3.length();j++)
                            s2.push_back(s3[j]);
                        s2.push_back(')');
                        if(mp.find(s2)==mp.end()){
                            mp.insert(s2);
                            ans.push_back(s2);
                            break;
                        }
                }
            }else{
                mp.insert(s);
                ans.push_back(s);
            }
        }

        return ans;
    }
};
