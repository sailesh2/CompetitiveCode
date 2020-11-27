class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int has[300]={0};
        for(int i=0;i<text.length();i++){
            has[text[i]]++;
        }

        int mini=has['b'];
        mini=min(mini,has['a']);
        mini=min(mini,has['l']/2);
        mini=min(mini,has['o']/2);
        mini=min(mini,has['n']);
        return mini;
    }
};
