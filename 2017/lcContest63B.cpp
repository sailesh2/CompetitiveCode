class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int k=0,val;
        char c;
        int ctr[300]={0};
        int drr[300];
        int mini=1000000000;
        for(int i=0;i<licensePlate.length();i++){
            c=licensePlate[i];
            if((c>='A' && c<='Z') || (c>='a' && c<='z')){

            if(c>='A' && c<='Z'){
                val=c-'A';
            }

            if(c>='a' && c<='z'){
                val=c-'a';
            }
            if(ctr[val]==0){
                drr[k++]=val;
            }
            ctr[val]++;
            }
        }

        int cnt;
        string save;
        for(int i=0;i<words.size();i++){
            int ctr2[300]={0};

            for(int j=0;j<words[i].length();j++){

                val=words[i][j]-'a';
                ctr2[val]++;

            }
            cnt=0;
            for(int j=0;j<k;j++){

                if(ctr2[drr[j]]<ctr[drr[j]]){

                    cnt=1;
                    break;
                }
            }
            if(cnt==0){
                if(words[i].length()<mini){
                    mini=words[i].length();
                    save=words[i];
                }

            }
        }
        return save;
    }
};
