class Solution {
private:
    string prefix(string s, int pc){
        string pre="";
        for(int i=0;i<pc;i++)
            pre.push_back(s[i]);
        return pre;
    }

    bool isRepeat(string prefix, string s){
        int i=0;
        int j=0;
        while(i<s.length()){
            if(prefix[j]!=s[i])
                return false;
            j=(j+1)%(prefix.length());
            i++;
        }

        return j==0;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.length(),str2.length());

        vector<int> divs;
        for(int i=1;i*i<=g;i++){
            if(g%i==0){
                divs.push_back(i);
                if(g!=i*i)
                    divs.push_back(g/i);
            }
        }

        sort(divs.begin(),divs.end());
        string gcdStr="";

        for(int i=0;i<divs.size();i++){
            string pre = prefix(str1,divs[i]);
            if(isRepeat(pre,str1) && isRepeat(pre,str2)){
                gcdStr=pre;
            }
        }

        return gcdStr;
    }
};
