#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    int n=s.length();
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string createPart(string s){
    string p="";
    for(int i=0;i<s.length()/2;i++){
        p.push_back(s[i]);
    }
    return p;
}

int cnt=0,multiplier=1;

int parts(string s, bool stopInOdd){
  //  cout<<s<<"\n";
    if(s.length()%2!=0){
        if(s.length()==1)
            return 0;
        else{
            if(!isPalindrome(s)){
                return 1;
            }else{
                if(stopInOdd){
                    cnt=1;
                    multiplier=2;
                    return 2;
                }else{
                    int v = parts(createPart(s),stopInOdd)*multiplier;
                    if(cnt==1){
                        cnt=0;
                        v--;
                    }
                    return v;
                }
            }
        }
    }

    if(!isPalindrome(s)){
        return 1;
    }else{
        int v = parts(createPart(s),stopInOdd)*multiplier;
        if(cnt==1){
            cnt=0;
            v--;
        }
        return v;
    }
}

int main(){
    string s;
    cin>>s;
    int ps,ex=0,mul=1;
    if(s.length()%2!=0){
        s=createPart(s);
        ex=2;

        if(isPalindrome(s)){
            mul=2;
        }else{
            mul=0;
        }
    }

    ps=parts(s,false);
    if(cnt==1)
        ex=0;
    if(ps==0){
        ps=parts(s,true);
        if(cnt==1)
        ex=0;

        if(ps==0)
        cout<<"Impossible";
        else
            cout<<ps*mul+ex;
    }else{
        cout<<ps*mul+ex;
    }
    return 0;
}
