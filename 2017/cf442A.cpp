#include<bits/stdc++.h>

using namespace std;

int cntSubstr(string s,string a){
    int counta = 0;
    int nPos = s.find(a, 0);
    while(nPos != string::npos)
    {
        counta++;
        nPos = s.find(a, nPos+1);
    }
    return counta;
}
int main(){
    string s;
    cin>>s;
    string a="Danil";
    int c=cntSubstr(s,a);
    string b="Olya";
    c=c+cntSubstr(s,b);
    string c2="Slava";
    c=c+cntSubstr(s,c2);
    string d="Ann";
    c=c+cntSubstr(s,d);
    string e="Nikita";
    c=c+cntSubstr(s,e);
    if(c==1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
