#include<bits/stdc++.h>

using namespace std;

string suffixThree(string s){
    int l=s.length();
    if(s[l-2]=='p' && s[l-1]=='o')
        return "FILIPINO";
    else if(s[l-4]=='d' && s[l-3]=='e' && s[l-2]=='s' && s[l-1]=='u')
        return "JAPANESE";
    else if (s[l-4]=='m' && s[l-3]=='a' && s[l-2]=='s' && s[l-1]=='u')
        return "JAPANESE";
    else
        return "KOREAN";
}

int main(){
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>s;
        cout<<suffixThree(s)<<"\n";
    }
    return 0;
}
