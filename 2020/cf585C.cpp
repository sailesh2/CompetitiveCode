#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    vector<int> vab,vba;
    int ab,ba,abP=0,baP=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            if(s[i]=='a' && t[i]=='b'){
                ab=i+1;
                abP++;
                vab.push_back(i+1);
            }
            if(s[i]=='b' && t[i]=='a'){
                ba=i+1;
                baP++;
                vba.push_back(i+1);
            }
        }
    }

    if((vab.size() + vba.size())%2==0){

        vector<pair<int,int> > ans;
        for(int i=0;i<vab.size();i=i+2){
            if(i+1<vab.size()){
                ans.push_back(make_pair(vab[i],vab[i+1]));
            }
        }
        for(int i=0;i<vba.size();i=i+2){
            if(i+1<vba.size()){
                ans.push_back(make_pair(vba[i],vba[i+1]));
            }
        }

        if(vab.size()%2!=0){
            ans.push_back(make_pair(vab[vab.size()-1],vab[vab.size()-1]));
            ans.push_back(make_pair(vab[vab.size()-1],vba[vba.size()-1]));
        }
        int k=ans.size();
        cout<<k<<"\n";
        for(int i=0;i<k;i++){
            cout<<ans[i].first<<" "<<ans[i].second<<"\n";
        }
    }else{
        cout<<"-1";
    }
    return 0;
}
