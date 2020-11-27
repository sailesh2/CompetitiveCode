#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,r,g,b;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>r>>g>>b;
        vector<int> v;
        v.push_back(r);
        v.push_back(g);
        v.push_back(b);
        sort(v.begin(),v.end());
        if(v[2]-v[0]>=v[1])
            cout<<v[1]+v[0]<<"\n";
        else{
            int d=v[2]-v[1];
            v[0]=v[0]-(v[2]-v[1]);
            d=d+v[0];
            v[1]=v[1]-(v[0]/2+v[0]%2);
            cout<<d+v[1]<<"\n";
        }
    }
    return 0;
}
