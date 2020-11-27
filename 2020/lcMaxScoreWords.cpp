class Solution {
private:
    int maxi=0;
    int l,w;

    vector<string> wor;
    vector<char> let;
    vector<int> sc;

    void maxScore(int index, int ctr, int* has, int score){
        if(ctr>l){
            return;
        }
        maxi=max(maxi,score);

        if(index==w){
            return;
        }

        maxScore(index+1,ctr,has,score);

        int cnt=0,a=0;
        for(int i=0;i<wor[index].length();i++){
            has[(int)wor[index][i]]--;
            a=a+sc[wor[index][i]-'a'];
        }
        for(int i=0;i<wor[index].length();i++){
            if(has[(int)wor[index][i]]<0){
                cnt=1;
                break;
            }
        }

        if(cnt==0){

            maxScore(index+1, ctr+wor[index].length(), has, score+a);

        }

       for(int i=0;i<wor[index].length();i++){
            has[(int)wor[index][i]]++;
        }
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        let=letters;
        wor=words;

        l=letters.size();
        w=words.size();

        sc=score;

        int has[300]={0};
        for(int i=0;i<l;i++)
            has[(int)let[i]]++;
        maxScore(0,0,has,0);
        return maxi;
    }
};
