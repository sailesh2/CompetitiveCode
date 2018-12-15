#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int convertToInt(string in){
        int n=0;
        for(int i=0;i<in.length();i++){
            n=n*10+(int)in[i]-48;
        }
        return n;
    }
    string bin(string in){
        int num=convertToInt(in);
        string s="";
        while(num>0){
            s=s+(char)(num%2+48);
            num=num/2;
        }
        string rev="";
        for(int i=s.length()-1;i>=0;i--){
            rev=rev+s[i];
        }
        return rev;
    }

    long long int getip(vector<int> digs){
        long long int p=1,s=0;
        for(int i=0;i<digs.size();i++){
            s=s+p*digs[i];
            p=p*256;
        }
        return s;
    }
    string convertToStr(int n){
        string s="";
        vector<int> digs;
        while(n>0){
            digs.push_back(n%10);
            n=n/10;
        }
        for(int i=digs.size()-1;i>=0;i--){
            s=s+(char)(digs[i]+48);
        }
        return s;
    }
    string ipToadd(long long int n){
        vector<int> digs;
        while(n>0){
            digs.push_back(n%256);
            n=n/256;
        }
        string s="";
        for(int i=digs.size()-1;i>=0;i--){
            if(i!=0)
            s=s+convertToStr(digs[i])+".";
            else
            s=s+convertToStr(digs[i]);

        }
        return s;
    }
    string cidr(long long int n){
        int ctr=0;
        while(n>0){
            if(n%2==1){
                break;
            }
            ctr++;
            n=n/2;
        }
        return convertToStr(32-ctr);
    }
    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }
public:
    vector<string> ipToCIDR(string ip, int range) {
        vector<string> classes=split(ip,range);

        vector<int> digs;
        digs.push_back(convertToInt(classes[3]));
        digs.push_back(convertToInt(classes[2]));
        digs.push_back(convertToInt(classes[1]));
        digs.push_back(convertToInt(classes[0]));
        vector<string> ans;
        string ansN,blocks;
        long long int finalIp=getip(digs);
        long long int save;
        int pos=log(finalIp);
        long long int next=pow(2,pos+1);
        while(range>0){
            while((next-finalIp)<=range){
                save=next;
                next=next*2;
            }
            ansN=ipToadd(next);
            blocks=cidr(next);
            ans.push_back(ansN+blocks);
            range=range-(save-finalIp);
        }
        return ans;
    }
};
