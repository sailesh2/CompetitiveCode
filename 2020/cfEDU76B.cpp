#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long int x,y;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        if(y<=x){
            cout<<"YES\n";
        }else{
            set<int> has;
            while(x<y && x>=1 && has.count(x)==0){
                has.insert(x);
                if(x%2==0){
                    x=3*(x/2);
                }else{
                    x--;
                }
            }
            if(x<y || x<1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
    }
    return 0;
}
