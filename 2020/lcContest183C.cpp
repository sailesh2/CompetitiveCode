class Solution {
private:

    bool validate(string ans, int a, int b, int c){
        return true;
    }

    char greatest(int a , int b, int c){
        if(a>=b && a>=c)
            return 'a';

        if(b>=a && b>=c)
            return 'b';

            return 'c';
    }

    string getLongestString(int a, int b, int c){
        string ans = "";
        int lets[3];
        lets[0]=a;
        lets[1]=b;
        lets[2]=c;

        char start = greatest(lets[0],lets[1],lets[2]);
        int cnt=2;
        while(1){
            if(lets[start-'a']>0){
                ans.push_back(start);
                lets[start-'a']--;
            }else{
                break;
            }
            if(cnt==2){
            if(lets[start-'a']>0){
                ans.push_back(start);
                lets[start-'a']--;
            }
            }

            if(start=='a'){
                start=lets[1]>=lets[2]?'b':'c';
                if(lets[start-'a']>=lets[0]){
                    cnt=2;
                }else{
                    cnt=1;
                }
            }
            else if(start=='b'){
                start=lets[0]>=lets[2]?'a':'c';
                if(lets[start-'a']>=lets[1]){
                    cnt=2;
                }else{
                    cnt=1;
                }
            }
            else{
                start=lets[0]>=lets[1]?'a':'b';
                if(lets[start-'a']>=lets[2]){
                    cnt=2;
                }else{
                    cnt=1;
                }
            }
        }

        return ans;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = getLongestString(a,b,c);
        if(validate(ans,a,b,c)){
            return ans;
        }else{
            return "";
        }
    }
};
