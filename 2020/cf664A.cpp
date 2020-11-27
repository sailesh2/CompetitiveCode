#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,r,g,b,w;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>r>>g>>b>>w;
        int mini = min(r,min(g,b));

        int ctr=0;
        if(r%2!=0)
            ctr++;
        if(g%2!=0)
            ctr++;
        if(b%2!=0)
            ctr++;
        if(w%2!=0)
            ctr++;

        if(ctr==2)
            cout<<"No\n";
        else if(ctr==0 || ctr==1)
            cout<<"Yes\n";
        else if(mini>0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
