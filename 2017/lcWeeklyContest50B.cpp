class MapSum {
public:
    map<string,int> trie;
    map<string,int>::iterator trieIt;
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        string s="";
        int v;
        for(int i=0;i<key.length();i++){
            s=s+key[i];
            trieIt = trie.find(s);
            v=0;
            if(trieIt!=trie.end()){
                v=trieIt->second;
                trie.erase(trieIt);
            }
            v=v+val;
            trie.insert(make_pair(s,v));
        }
    }

    int sum(string prefix) {
        string s="";
        int v=0;
        for(int i=0;i<key.length();i++){
            s=s+key[i];
            trieIt=trie.find(s);
            if(trieIt != trie.end()){
                v=v+trieIt->second;
            }
        }
        return v;
    }
};
