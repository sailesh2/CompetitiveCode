class Solution {
public:
    string originalDigits(string s) {
        int has[300]={0};
        for(int i=0;i<s.length();i++){
            has[s[i]]++;
        }
        string digsUnique[10]={"z","w","u","x","g","o","h","f","v","n"};
        string digsinWords[10]={"zero","two","four","six","eight","one","three","five","seven","nine"};
        int digsinNum[10]={0,2,4,6,8,1,3,5,7,9};
        int order[10]={0,5,1,6,2,7,3,8,4,9};
        string ans="";
        int ctr[10];
        for(int j=0;j<10;j++){
            s=digsUnique[j];
            int mini=has[s[0]];
            if(j==9)
                mini=mini/2;
            s=digsinWords[j];
            for(int i=0;i<s.length();i++){
                has[s[i]]=has[s[i]]-mini;
            }
            ctr[digsinNum[j]]=(mini);
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<ctr[i];j++){
                ans=ans+(char)(digsinNum[order[i]]+48);
            }
        }
        return ans;
    }
};
