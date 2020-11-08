#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        long long int p,q,ev,od,ev2,od2;
        cin>>n;

        ev=0;
        ev2=0;
        od=0;
        od2=0;
        for(int j=0;j<n;j++){
            cin>>p;
            if(p%2==0)
                ev++;
            else
                od++;
        }
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>q;
            if(q%2==0)
                ev2++;
            else
                od2++;
        }

        long long int lines=ev*ev2 + od*od2;
        cout<<lines<<"\n";
    }
    return 0;
}
