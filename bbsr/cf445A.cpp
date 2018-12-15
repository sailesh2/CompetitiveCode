#include<bits/stdc++.h>

using namespace std;

int main(){
    string f,l;
    cin>>f>>l;
    vector<string> v;
    string login="";
    string pos;
    for(int i=0;i<f.length();i++){
        login=login+f[i];
        pos=login;
        for(int j=0;j<l.length();j++){
            pos=pos+l[j];
            v.push_back(pos);
        }
    }
    sort(v.begin(),v.end());
    cout<<v[0];
    return 0;
}
