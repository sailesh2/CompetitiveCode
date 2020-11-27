class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int l=s1.length();
        int cnt=0;
        for(int i=0;i<l;i++){
            if(s1[i]!=s2[i]){
                for(int j=i+1;j<l;j++){
                    if(s1[j]==s1[i] && s1[j]!=s2[j]){
                        char temp=s1[j];
                        s1[j]=s2[i];
                        s2[i]=temp;
                        cnt++;
                        break;
                    }
                }
            }
            if(s1[i]!=s2[i]){
                for(int j=i+1;j<l;j++){
                    if(s2[j]==s2[i] && s1[j]!=s2[j]){
                        char temp=s2[j];
                        s2[j]=s1[i];
                        s1[i]=temp;
                        cnt++;
                        break;
                    }
                }
            }
            if(s1[i]!=s2[i]){
                for(int j=i+1;j<l;j++){
                    if(s2[j]==s1[i] && s1[j]!=s2[j]){
                        char temp=s2[j];
                        s2[j]=s1[j];
                        s1[j]=temp;

                        temp=s1[j];
                        s1[j]=s2[i];
                        s2[i]=temp;

                        cnt=cnt+2;
                        break;
                    }
                }
            }

            if(s1[i]!=s2[i])
                return -1;
        }

        return cnt;
    }
};
