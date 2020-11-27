#include<bits/stdc++.h>

using namespace std;


string removeEnd(string s){
    string formatted="";
    for(int i=0;i<s.length()-1;i++){
        formatted.push_back(s[i]);
    }

    return formatted;
}

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string formatted="";
    int turn=0;
    int save=-1;
    for(int i=0;i<n;i=i+2){
        if(i+1>=n){
            formatted.push_back(s[i]);
            break;
        }
        if(s[i]==s[i+1]){
            while(i<n-1){
                if(s[i]==s[i+1])
                    i++;
                else
                    break;
            }

            formatted.push_back(s[i]);
            if(i+1<n)
                formatted.push_back(s[i+1]);

        }else{
            formatted.push_back(s[i]);
            formatted.push_back(s[i+1]);
        }
    }

    if(formatted.length()%2!=0)
        formatted = removeEnd(formatted);

    cout<<s.length()-formatted.length()<<"\n";
    cout<<formatted;

    return 0;
}
