#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n;
    map<int,int> mp;
    map<int,int>::iterator mpIt;
    for(int i=0;i<n;i++){
        cin>>x;
        mpIt=mp.find(x);
        if(mpIt!=mp.end()){
            mp.erase(mpIt);
        }
        mp.insert(make_pair(x,i+1));

    }
    int q;
    set<int> qr;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x;
        if(qr.count(x)==0){
            mpIt=mp.find(x);
            if(mpIt==mp.end())
                cout<<"-1";
            else
                cout<<mpIt->second;
        }else{
            cout<<"-1";
        }
        qr.insert(x);
        cout<<"\n";
    }
    return 0;
}
