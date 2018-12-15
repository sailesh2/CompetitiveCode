#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    string exp;

    pair<int,int> evalAddMul(int ind,map<string,int> mp){
        int v1=0,v2=0,p,cnt,ctr;
        string s;
        map<string,int>::iterator mpIt;
        if(exp[ind]=='(')
            v1=eval(ind+1,mp);
        else{
            p=0;
            cnt=0;
            s="";
            for(int i=ind;exp[i]!=' ';i++){
                if(exp[i]>='0' && exp[i]<='9' && cnt==0){
                    p=p*10+(int)(exp[i]-48);
                    s=s+exp[i];
                }else{
                    cnt=1;
                    s=s+exp[i];
                }
            }
            if(cnt==0)
                v1=p;
            else{
                mpIt=mp.find(s);
                v1=mpIt->second;
            }
        }
        ctr=0;
        for(int i=ind;i<exp.size();i++){
            if(exp[i]=='('){
                ctr++;
            }else if(exp[i]==')'){
                ctr--;
            }
            if(ctr==0 && exp[i]==' '){
                ind=i+1;
                break;
            }
        }


        if(exp[ind]=='(')
            v2=eval(ind+1,mp);
        else{
            p=0;
            cnt=0;
            s="";
            for(int i=ind;exp[i]!=' ' && exp[i]!=')';i++){
                if(exp[i]>='0' && exp[i]<='9' && cnt==0){
                    p=p*10+(int)(exp[i]-48);
                    s=s+exp[i];
                }else{
                    cnt=1;
                    s=s+exp[i];
                }
            }
            if(cnt==0)
                v2=p;
            else{
                mpIt=mp.find(s);
                v2=mpIt->second;
            }
        }
        return make_pair(v1,v2);
    }

    int evalLet(int ind,map<string,int> mp){
        string s="",s2="";
        int i,v,ctr,p,cnt;

        while(1){
            s="";
            for(i=ind;exp[i]!=' ' && exp[i]!=')';i++){
                s=s+exp[i];
            }
            if(exp[i]==')'){
                return (mp.find(s))->second;
            }
            ind=i+1;
            if(exp[ind]=='('){
                v=eval(ind+1,mp);
                mp.insert(make_pair(s,v));
            }else{
                p=0;
                cnt=0;
                s2="";
                for(i=ind;exp[i]!=' ';i++){
                    if(exp[i]>='0' && exp[i]<='9' && cnt==0){
                        p=p*10+(int)(exp[i]-48);
                        s2=s2+exp[i];
                    }else{
                        cnt=1;
                        s2=s2+exp[i];
                    }
                }
                if(cnt==0){
                    mp.insert(make_pair(s,p));
                }else{
                    p=(mp.find(s2))->second;
                    mp.insert(make_pair(s,p));
                }

            }
            ctr=0;
            for(i=ind;i<exp.size();i++){
                if(exp[i]=='(')
                    ctr++;
                if(exp[i]==')')
                    ctr--;
                if(ctr==0 && exp[i]==' ')
                    break;
            }
            ind=i+1;
        }
    }

    int eval(int ind,map<string,int> mp){
        pair<int,int> p;
        if(exp[ind]=='a' && exp[ind+1]=='d' && exp[ind+2]=='d'){
            p=evalAddMul(ind+4,mp);
            return p.first+p.second;
        }
        if(exp[ind]=='m' && exp[ind+1]=='u' && exp[ind+2]=='l' && exp[ind+3]=='t'){
            p=evalAddMul(ind+5,mp);
            return p.first*p.second;
        }
        if(exp[ind]=='l' && exp[ind+1]=='e' && exp[ind+2]=='t'){
            return evalLet(ind+4,mp);
        }
    }
public:
    int evaluate(string expression) {
        exp=expression;
        map<string,int> mp;
        return eval(1,mp);
    }
};
