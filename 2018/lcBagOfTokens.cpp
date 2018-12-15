class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int p) {
        sort(tokens.begin(),tokens.end());

        int start=0,last=tokens.size()-1;
        int maxPoints=0;
        while(start<=last){
            long long sm=0;
            int points=0;
            for(int i=start;i<=last;i++){
                sm=sm+tokens[i];
                if(sm<=p){
                    points++;
                }
            }
            maxPoints=max(maxPoints,points);
            if(points>0){
                p=p+tokens[last]-tokens[start];
                last--;
                start++;
            }else{
                break;
            }
        }
        return maxPoints;
    }
};
