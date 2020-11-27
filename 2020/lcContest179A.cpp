class Solution {
public:
    string generateTheString(int n) {
        string s= "";
        if(n%2==0){
            s.push_back('a');
            n--;
        }

        for(int i=0;i<n;i++)
            s.push_back('b');
        return s;
    }
};
