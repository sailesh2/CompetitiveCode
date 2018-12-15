#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=1;
        vector<char> ans;
        vector<int> dig;
        char save=chars[0];

        for(int i=1;i<chars.size();i++){
            if(chars[i]==save){
                cnt++;
            }else{
                ans.push_back(save);
                if(cnt>1){
                    dig.clear();
                    while(cnt>0){
                        dig.push_back(cnt%10);
                        cnt=cnt/10;
                    }
                    for(int j=dig.size()-1;j>=0;j--){
                        ans.push_back((char)dig[j]+48);
                    }
                }
                save=chars[i];
                cnt=1;
            }
        }
        ans.push_back(save);
        if(cnt>1){
            dig.clear();
            while(cnt>0){
                dig.push_back(cnt%10);
                cnt=cnt/10;
            }
            for(int j=dig.size()-1;j>=0;j--){
                ans.push_back((char)dig[j]+48);
            }
        }
        chars=ans;
        return ans.size();
    }
};
