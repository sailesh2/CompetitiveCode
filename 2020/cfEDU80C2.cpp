#include<bits/stdc++.h>

using namespace std;
int n,m;
set<pair<string,string>> mp;

string str(int v){
    string s="";
    string srev="";
    while(v>0){
        s.push_back(((char)(v%10+48)));
        v=v/10;
    }
    for(int i=s.length()-1;i>=0;i--)
        srev.push_back(s[i]);
    return srev;
}

string pushStr(string a, string b){
    for(int i=0;i<b.length();i++){
        a.push_back(b[i]);
    }
    return a;
}

int fun(int index, int vala, int valb, string a, string b){
    int s=0;
    if(index==m-1){

    cout<<index<<"=="<<a<<"=="<<b<<"\n";
        if(mp.count(make_pair(a,b))==0){
            mp.insert(make_pair(a,b));
            return 1;
        }
        return 0;
    }

    for(int i=vala;i<=n;i++){
        for(int j=valb;j>=1;j--){
            if(i<=j){
                string a2=pushStr(a,str(i));
                string b2=pushStr(b,str(j));
                s=s+fun(index+1,i,j,a2,b2);

            }
        }
    }
    return s;
}

int main(){
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(i<=j){
            string a=pushStr("",str(i));
            string b=pushStr("",str(j));
            s=s+fun(0,i,j,a,b);
            }
        }
    }
    cout<<s;
    return 0;
}
