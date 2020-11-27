#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;
    int x;
    for(int i=0;i<t;i++){
        cin>>n;
        map<int,int> mp;
        map<int,int>::iterator mpIt;
        int mini=n+1;
        for(int i=0;i<n;i++){
            cin>>x;
            mpIt=mp.find(x);
            if(mpIt!=mp.end()){
                int pos=mpIt->second;
                mini=min(mini,i-pos);
                mp.erase(mpIt);
            }
            mp.insert(make_pair(x,i));
        }
        if(mini==n+1)
            cout<<"-1\n";
        else
            cout<<mini+1<<"\n";
    }
    return 0;
}
