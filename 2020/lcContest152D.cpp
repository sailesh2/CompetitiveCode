class Solution {
private:
    int letterPresent[100005][27]={0};
    vector<int> puzzleBuckets[27];
    vector<int> wordBuckets[27];
    vector<string> puzzlesSeq[100005];
    string wordHasStore[100005];

    void hasWords(vector<string>& words){
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].length();j++){
                letterPresent[i][words[i][j]-'a']++;
            }
        }
    }

    void bucketPuzzles(vector<string>& puzzles){
        for(int i=0;i<puzzles.size();i++){
            puzzleBuckets[puzzles[i][0]-'a'].push_back(i);
        }
    }

    void bucketWords(vector<string>& words){
        for(int i=0;i<26;i++){
            for(int j=0;j<words.size();j++){
                if(letterPresent[j][i]>0){
                    wordBuckets[i].push_back(j);
                }
            }
        }
    }

    string generateHas(string input){
        string hasStr="";
        int hasCtr[27]={0};
        for(int i=0;i<input.length();i++){
            if(hasCtr[input[i]-'a']==0){
                hasStr.push_back(input[i]);
                hasCtr[input[i]-'a']++;
            }
        }

        sort(hasStr.begin(),hasStr.end());
        return hasStr;
    }

    void generateSequence(string inp, string s, int index, vector<string>& subSeq){
        if(index==inp.length()){
            if(s.length()>0)
            subSeq.push_back(s);
            return;
        }

        s.push_back(inp[index]);
        generateSequence(inp,s,index+1,subSeq);
        s.pop_back();
        generateSequence(inp,s,index+1,subSeq);
    }

    vector<string> generateSubSeq(string inp){
        vector<string> subSeq;
        generateSequence(inp,"",0,subSeq);
        return subSeq;
    }

    vector<int> calculateValidWords(vector<string>& words, vector<string>& puzzles){

        vector<int> ans;
        for(int i=0;i<puzzles.size();i++)
            ans.push_back(0);

        for(int i=0;i<26;i++){
            map<string,int> hashCnt;
            map<string,int>::iterator hashCntIt;
            if(puzzleBuckets[i].size()==0)
                continue;
            for(int j=0;j<wordBuckets[i].size();j++){
                string hasStr=wordHasStore[wordBuckets[i][j]];
                if(hasStr.length()<=7){
                    hashCntIt=hashCnt.find(hasStr);
                    int v=0;
                    if(hashCntIt!=hashCnt.end()){
                        v=hashCntIt->second;
                        hashCnt.erase(hashCntIt);
                    }
                    v++;
                    hashCnt.insert(make_pair(hasStr,v));
                }
            }

            for(int j=0;j<puzzleBuckets[i].size();j++){
                vector<string> subSeq =puzzlesSeq[puzzleBuckets[i][j]];
                int val=0;
                for(int i=0;i<subSeq.size();i++){
                    hashCntIt=hashCnt.find(subSeq[i]);
                    int v=0;
                    if(hashCntIt!=hashCnt.end()){
                        v=hashCntIt->second;
                    }
                    val=val+v;
                }
                ans[puzzleBuckets[i][j]]=val;
            }
        }

        return ans;
    }

    void storePuzzleSeq(vector<string>& puzzles){
        for(int i=0;i<puzzles.size();i++){
            string hasStr=puzzles[i];
            sort(hasStr.begin(),hasStr.end());
            vector<string> seq = generateSubSeq(hasStr);
            puzzlesSeq[i]=seq;
        }
    }

    void storeWordHasStore(vector<string>& words){
        for(int i=0;i<words.size();i++){
            string w=words[i];
            wordHasStore[i]=generateHas(w);
        }
    }

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        hasWords(words);

        bucketPuzzles(puzzles);
        bucketWords(words);

        storeWordHasStore(words);
        storePuzzleSeq(puzzles);
        return calculateValidWords(words,puzzles);
    }
};
