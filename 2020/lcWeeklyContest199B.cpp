class Solution {
public:
    int minFlips(string target) {
        char status='0';
        int cnt=0;
        for(int i=0;i<target.length();i++){
            if(target[i]!=status){
                status=target[i];
                cnt++;
            }
        }
        return cnt;
    }
};
