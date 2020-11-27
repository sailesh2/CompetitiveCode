#include<bits/stdc++.h>

using namespace std;

string match = "abacaba";

int countSubs(string s){
    int ctr=0;
    int n = s.length();
    for(int i=0;i<s.length();i++){
        int cnt=0;
        if(i+7<=n){
            for(int j=i;j<i+7;j++){
                if(s[j]!=match[j-i]){
                    cnt=1;
                    break;
                }
            }
            if(cnt==0)
                ctr++;
        }
    }
    return ctr;
}

pair<string,bool> deform(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='?'){
            s[i]='x';
        }
    }
    return make_pair(s,true);
}

pair<string,bool> canForm(string s){
    if(s.length()!=7)
        return make_pair(s,false);

    for(int i=0;i<7;i++){
        if(s[i]=='?'){
            s[i]=match[i];
        }else{
            if(s[i]!=match[i])
                return make_pair(s,false);
        }
    }


    return make_pair(s,true);
}

pair<string,bool> form(string s){
    int cnt=0;
    int n=s.length();
    for(int i=0;i<s.length();i++){
        string temp = "";
        for(int j=i;j<min(i+7,n);j++){
            temp.push_back(s[j]);
        }
        pair<string,bool> p = canForm(temp);
        if(p.second){
            if(i-4>=0 && s[i-4]=='a' && s[i-3]=='b' && s[i-2]=='a' && s[i-1]=='c'){

            }else if(i-6>=0 && s[i-6]=='a' && s[i-5]=='b' && s[i-4]=='a' && s[i-3]=='c' && s[i-2]=='a' && s[i-1]=='b'){

            }else if(i+10<=n-1 && s[i+7]=='c' && s[i+8]=='a' && s[i+9]=='b' && s[i+10]=='a'){

            }else if(i+12<=n-1 && s[i+7]=='b' && s[i+8]=='a' && s[i+9]=='c' && s[i+10]=='a' && s[i+11]=='b'&& s[i+12]=='a'){

            }
            else{
                cnt=1;
                temp=p.first;
                for(int j=i;j<min(i+7,n);j++){
                    s[j]=temp[j-i];
                }

                break;
            }
        }
    }

    return make_pair(deform(s).first,cnt==1);
}

pair<string,bool> convert(string s){
    int c = countSubs(s);
    if(c>1){
        return make_pair(s,false);
    }else if(c==1){
        return deform(s);
    }else{
        return form(s);
    }
}

int main(){
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        string s;
        cin>>s;
        pair<string,bool> p=convert(s);
        if(p.second){
            cout<<"YES\n";
            cout<<p.first<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
