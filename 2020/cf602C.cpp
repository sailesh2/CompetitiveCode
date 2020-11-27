#include<bits/stdc++.h>

using namespace std;

string getFinalString(int n, int k){
    string s="";
    for(int i=0;i<(k-1);i++){
        s.push_back('(');
        s.push_back(')');
    }
    int rem=n-(2*(k-1));
    rem=rem/2;
    for(int i=0;i<rem;i++)
        s.push_back('(');
    for(int i=0;i<rem;i++)
        s.push_back(')');
    return s;
}

int main(){
    int t,n,k;
    cin>>t;
    string s,s2;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        cin>>s;
        vector<pair<int,int> > ans;
        s2=getFinalString(n,k);
       // cout<<s2;
        for(int j=0;j<n;j++){
            if(s[j]!=s2[j]){
                string temp="";
                for(int l=j;l<n;l++){
                    temp.push_back(s[l]);
                    if(s[l]==s2[j]){
                        break;
                    }
                }
                int e=temp.length();
                int ctr=0;
                for(int l=j;l<j+e;l++){
                    s[l]=temp[e-1-ctr];
                    ctr++;
                }
                ans.push_back(make_pair(j+1,j+e));
            }
        }
        cout<<ans.size()<<"\n";
        for(int j=0;j<ans.size();j++){
            cout<<ans[j].first<<" "<<ans[j].second<<"\n";
        }
    }
    return 0;
}
