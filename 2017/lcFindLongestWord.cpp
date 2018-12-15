class Solution {
private:
    string longest = "";
    int maxi=0;
    set<string> dict;
    set<pair<string,int> > has;
    set<pair<string,int> >::iterator hasIt;
    void lwDP(int ind,string formed,string s){
        if(ind==s.length()){
            if(dict.count(formed)>0){
                if(formed.length()>maxi){
                    maxi=formed.length();
                    longest=formed;
                }
            }
            return;
        }
        hasIt=has.find(make_pair(formed,ind+1));
        if(hasIt==has.end()){
            lwDP(ind+1,formed,s);
            has.insert(make_pair(formed,ind+1));
        }

        hasIt=has.find(make_pair(formed+s[ind],ind+1));
        if(hasIt==has.end()){
            lwDP(ind+1,formed+s[ind],s);
            has.insert(make_pair(formed+s[ind],ind+1));
        }
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        for(int i=0;i<d.size();i++){
            dict.insert(d[i]);
        }
        lwDP(0,"",s);
        return longest;
    }
};
