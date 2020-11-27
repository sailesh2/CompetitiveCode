#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    int m,c,x;
    for(int i=0;i<q;i++){
        cin>>m>>c>>x;
        int minMC=min(m,c);
        m=m-minMC;
        c=c-minMC;
        int t=minMC;
        if(t>m+c+x){
            int rem=t-(m+c+x);
            t=m+c+x;
            t=t+2*(rem/3);
            if(rem%3==2)
                t++;

        }
        cout<<t<<"\n";
    }
    return 0;
}
