#include<bits/stdc++.h>

using namespace std;
long long int u,v;
string uBin, vBin;
long long int a,b,c;
bool third = false;


long long int convertToInt(string s){
    long long int num=0;
    for(int i=0;i<s.length();i++){
        num=num*2+(long long int)(s[i]-'0');
    }
    return num;
}

string bin(long long int num){
    string s="";
    while(num>0){
        s.push_back((char)(num%2+48));
        num=num/2;
    }
    return s;
}

string reverseStr(string s){
    string rev="";
    for(int i=s.length()-1;i>=0;i--)
        rev.push_back(s[i]);
    return rev;
}

void storeBin(){
    uBin = bin(u);
    vBin = bin(v);
    int diff = vBin.length() - uBin.length();
    for(int i=0;i<diff;i++)
        uBin.push_back('0');
    uBin=reverseStr(uBin);
    vBin=reverseStr(vBin);
}

bool possible(){
    int l=uBin.length();
    int carry=0;
    string aStr="",bStr="",cStr="";
    for(int i=0;i<l;i++){
        aStr.push_back('0');
        bStr.push_back('0');
        cStr.push_back('0');
        if(uBin[i]==vBin[i]){
            if(uBin[i]=='0'){
                if(carry==0){
                    aStr[i]='0';
                    bStr[i]='0';
                }else{
                    aStr[i]='1';
                    bStr[i]='1';
                }
            }else{
                if(carry==0){
                    aStr[i]='1';
                    bStr[i]='0';
                }else{
                    aStr[i]='1';
                    bStr[i]='1';
                    cStr[i]='1';
                    third=true;
                }
            }
            carry=0;
        }else{
            if(uBin[i]=='0'){
                if(carry==0){
                    aStr[i]='0';
                    bStr[i]='0';
                }else{
                    aStr[i]='1';
                    bStr[i]='1';
                }
            }else{
                if(carry==0){
                    return false;
                }else{
                    aStr[i]='1';
                    bStr[i]='0';
                }
            }
            carry=1;
        }
    }

    if(carry==1)
        return false;

    a=convertToInt(aStr);
    b=convertToInt(bStr);
    c=convertToInt(cStr);
    return true;
}

int main(){
    cin>>u>>v;
    if(u>v)
        cout<<"-1";
    else if(u==v){
        if(u==0)
            cout<<"0";
        else{
            cout<<"1\n";
            cout<<u;
        }
    }else{
        storeBin();
        if(possible()){
            if(third){
                cout<<"3\n";
                cout<<a<<" "<<b<<" "<<c;
            }else{
                cout<<"2\n";
                cout<<a<<" "<<b;
            }
        }else{
            cout<<"-1";
        }
    }
    return 0;
}
