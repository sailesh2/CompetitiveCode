class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        int cnt=0,savei,savej;
        while(i<=j){
            if(s[i]!=s[j]){
                savei=i;
                savej=j;
                cnt=1;
                break;
            }
            i++;
            j--;
        }
        if(cnt==0){
            return cnt==0;
        }else{
            string sa;
            for(int k=0;k<s.length();k++){
                if(k!=savei){
                    sa=sa+s[k];
                }
            }

            i=0;
            j=sa.length()-1;
            int cnt1=0;
            while(i<=j){
                if(sa[i]!=sa[j]){
                    cnt1=1;
                    break;
                }
                i++;
                j--;
            }

            if(cnt1==0){
                return cnt1==0;
            }else{
                string sb;
                for(int k=0;k<s.length();k++){
                    if(k!=savej){
                        sb=sb+s[k];
                    }
                }

                i=0;
                j=sb.length()-1;
                int cnt2=0;
                while(i<=j){
                    if(sb[i]!=sb[j]){
                        cnt2=1;
                        break;
                    }
                    i++;
                    j--;
                }
                return cnt2==0;
            }
        }
    }
};
