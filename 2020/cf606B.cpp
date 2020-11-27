#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,x;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int> v;
        for(int j=0;j<n;j++){
            cin>>x;
            if(x%2==0){
                v.push_back(x);
            }
        }
        int ctr=0;
        set<int> has;
        sort(v.begin(),v.end());
        for(int j=v.size()-1;j>=0;j--){
            x=v[j];
            if(has.count(x)==0){
                while(x%2==0){
                    has.insert(x);
                    ctr++;
                    x=x/2;
                }
            }
        }
        cout<<ctr<<"\n";
    }
    return 0;
}
