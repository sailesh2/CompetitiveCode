#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int c;
    vector<int> inc;
    vector<int> dec;
    int cnt=0;
    int distinct[200005]={0};
    for(int i=0;i<n;i++){
        cin>>c;
        distinct[c]++;
        if(distinct[c]==1){
            inc.push_back(c);
        }else if(distinct[c]==2){
            dec.push_back(c);
        }
        else{
            cnt=1;
        }
    }
    if(cnt==1){
        cout<<"NO";
    }else{
        cout<<"YES\n";
        sort(inc.begin(),inc.end());
        sort(dec.begin(),dec.end());
        cout<<inc.size()<<"\n";
        for(int i=0;i<inc.size();i++){
            cout<<inc[i]<<" ";
        }
        cout<<"\n";
        cout<<dec.size()<<"\n";
        for(int i=dec.size()-1;i>=0;i--){
            cout<<dec[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
