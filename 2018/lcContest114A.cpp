class Solution {
private:
    int sortOrder[300]={0};

    void storeOrder(string order){
        int ctr=0;
        for(int i=0;i<order.length();i++){
            sortOrder[order[i]]=++ctr;
        }
    }

    bool lesser(string a , string b){
        for(int i=0;i<min(a.length(),b.length());i++){
            if(sortOrder[a[i]]>sortOrder[b[i]]){
                return false;
            }else if(sortOrder[a[i]]<sortOrder[b[i]]){
                return true;
            }
        }
        return a.length()<=b.length();
    }

    bool isSorted(vector<string>& words){
        for(int i=0;i<words.size()-1;i++){
            if(!lesser(words[i],words[i+1])){
                return false;
            }
        }
        return true;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        storeOrder(order);
        return isSorted(words);
    }
};
