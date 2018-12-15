#include<bits/stdc++.h>

using namespace std;

bool isSuffix(string child,string parent){
    int cnt=0;
    int j=0;
    int ps=parent.length()-1;
    if(child.compare(parent)==0){
        return false;
    }
    for(int i=child.length()-1;i>=0;i--){
        if(ps-j<0){
            cnt=1;
            break;
        }
        if(parent[ps-j]!=child[i]){
            cnt=1;
            break;
        }
        j++;
    }
    return cnt==0;
}
int main(){

    map<string,vector<string> > phoneBook;
    map<string,vector<string> >::iterator phoneFind;

    map<string,set<string> > phoneBookClear;
    map<string,set<string> >::iterator phoneFindClear;

    int n,m;
    cin>>n;
    string s,p;
    vector<string> v;
    vector<string> st;
    set<string> vpure;
    set<string>::iterator vpureIt;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>m;
        phoneFind=phoneBook.find(s);

        if(phoneFind!=phoneBook.end()){
            v=phoneFind->second;
            phoneBook.erase(phoneFind);
        }else{
            st.push_back(s);
            v.clear();
        }
        for(int j=0;j<m;j++){
            cin>>p;
            v.push_back(p);
        }
        phoneBook.insert(make_pair(s,v));
    }
    int cnt;
    for(int i=0;i<st.size();i++){
        s=st[i];
        phoneFind=phoneBook.find(s);
        v=phoneFind->second;
        vpure.clear();
        for(int j=0;j<v.size();j++){
           p=v[j];
           cnt=0;
           for(int k=0;k<v.size();k++){
                if(k!=j){
                   if(isSuffix(p,v[k])){
                        cnt=1;
                        break;
                   }
                }
           }
           if(cnt==0){
                vpure.insert(p);
           }
        }
        phoneBookClear.insert(make_pair(s,vpure));
    }
    cout<<st.size()<<"\n";
    for(int i=0;i<st.size();i++){
        s=st[i];
        cout<<s<<" ";
        phoneFindClear=phoneBookClear.find(s);
        vpure=phoneFindClear->second;
        cout<<vpure.size()<<" ";
        for(vpureIt=vpure.begin();vpureIt!=vpure.end();vpureIt++){
            cout<<*vpureIt<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
