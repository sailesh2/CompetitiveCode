class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l1>l2)
            return false;

        char has1[300]={0};
        char has2[300]={0};

        for(int i=0;i<l1;i++){
            has1[(int)s1[i]]++;
        }

        for(int i=0;i<l1;i++){
            has2[(int)s2[i]]++;
        }

        int cnt=0;
        for(char c = 'a';c<='z';c++){
            if(has1[(int)c]!=has2[(int)c]){
                cnt=1;
                break;
            }
        }

        if(cnt==0)
            return true;

        for(int i=l1;i<l2;i++){
            has2[(int)s2[i-l1]]--;
            has2[(int)s2[i]]++;

            cnt=0;
            for(char c = 'a';c<='z';c++){
                if(has1[(int)c]!=has2[(int)c]){
                    cnt=1;
                    break;
                }
            }

            if(cnt==0)
                return true;
        }

        return false;
    }
};
