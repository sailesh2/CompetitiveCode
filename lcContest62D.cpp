#include<bits/stdc++.h>

using namespace std;

class WordFilter {
private:
    map<pair<string,string>,int> mp;
    map<pair<string,string>,int>::iterator mpIt;
public:
    WordFilter(vector<string> words) {

        string s,preS,sufS;
        vector<string> pre;
        vector<string> suf;
        int power;
        for(int i=0;i<words.size();i++){

            s=words[i];
            preS="";
            sufS="";
            pre.clear();
            suf.clear();
            pre.push_back(preS);
            suf.push_back(sufS);
            for(int j=0;j<s.length();j++){
                preS=preS+s[j];
                pre.push_back(preS);
            }
            for(int j=s.length()-1;j>=0;j--){
                sufS=s[j]+sufS;
                suf.push_back(sufS);
            }
            for(int j=0;j<pre.size();j++){
                for(int k=0;k<suf.size();k++){
                    mpIt=mp.find(make_pair(pre[j],suf[k]));
                    if(mpIt!=mp.end()){
                        power=mpIt->second;
                        if(i>power){
                            mp.erase(mpIt);
                            mp.insert(make_pair(make_pair(pre[j],suf[k]),i));
                        }
                    }else{
                        mp.insert(make_pair(make_pair(pre[j],suf[k]),i));
                    }
                }
            }
        }
        /*for(mpIt=mp.begin();mpIt!=mp.end();mpIt++){
            cout<<(mpIt->first).first<<" "<<(mpIt->first).second<<" "<<(mpIt->second)<<"\n";
        }*/
    }

    int f(string prefix, string suffix) {
        mpIt=mp.find(make_pair(prefix,suffix));
        if(mpIt==mp.end())
            return -1;
        else
            return mpIt->second;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */

int main(){
    vector<string> inp;
    inp.push_back("pop");
    WordFilter wordFilter(inp);
    cout<<wordFilter.f("","");
}
