#include<bits/stdc++.h>

using namespace std;

string rev(string s){
    string r="";
    for(int i=s.length()-1;i>=0;i--)
        r.push_back(s[i]);
    return r;
}

int main(){
    int t;
    int n;
    string s;
    cin>>t;
    int zz,oo,zo,oz;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int> vzo,voz;
        zz=0;
        oo=0;
        zo=0;
        oz=0;
        string srr[n];
        set<string> vzost,vozst;
        for(int j=0;j<n;j++){
            cin>>s;
            if(s[0]=='0' && s[s.length()-1]=='0'){
                zz=1;
            }
            if(s[0]=='1' && s[s.length()-1]=='1'){
                oo=1;
            }
            if(s[0]=='0' && s[s.length()-1]=='1'){
                zo++;
                vzo.push_back(j);
                vzost.insert(s);
            }
            if(s[0]=='1' && s[s.length()-1]=='0'){
                oz++;
                voz.push_back(j);
                vozst.insert(s);
            }
            srr[j]=s;
        }
        if(zo==0 && oz==0 && zz==1 && oo==1){
            cout<<"-1\n";
        }else{
            if(abs(zo-oz)/2 ==0){
                cout<<"0\n";
            }else{
                int ctr=0;
                int cnt=0;
                vector<int> ans;
                if(zo>oz){
                    for(int j=0;j<vzo.size();j++){
                        if(vozst.count(rev(srr[vzo[j]]))==0){
                            ctr++;
                            ans.push_back(vzo[j]);
                            if(ctr==abs(zo-oz)/2)
                            {
                                cnt=1;
                                break;
                            }
                        }
                    }
                }else{
                    for(int j=0;j<oz;j++){
                        if(vzost.count(rev(srr[voz[j]]))==0){
                            ctr++;
                            ans.push_back(voz[j]);
                            if(ctr==abs(zo-oz)/2)
                            {
                                cnt=1;
                                break;
                            }
                        }

                    }
                }

                if(cnt==1){
                    cout<<abs(zo-oz)/2<<"\n";
                    for(int j=0;j<ans.size();j++){
                        cout<<ans[j]+1<<" ";
                    }
                }else{
                    cout<<"-1";
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
