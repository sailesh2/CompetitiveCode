#include<bits/stdc++.h>

using namespace std;

class BuffaloBuffalo{
public:
    string check(string in){
        vector<string> buff;
        string s="";
        int cnt=0,ctr=0;
        for(int i=0;i<in.length();i++){
            if(in[i]==' '){
                buff.push_back(s);
                ctr++;
                if(ctr>1){
                    cnt=1;
                    break;
                }
                s="";
            }else{
                ctr=0;
                s=s+in[i];
            }
        }
        buff.push_back(s);
        if(cnt==1){
            return "Not good";
        }else{
            if(in[0]==' ' || in[in.length()-1]==' '){
                cnt=1;
            }
            if(cnt==1){
                return "Not good";
            }else{
                for(int i=0;i<buff.size();i++){
                    if(buff[i].compare("buffalo")!=0){
                        cnt=1;
                        break;
                    }
                }
                if(cnt==1){
                    return "Not good";
                }else{
                    return "Good";
                }
            }
        }
    }
};
