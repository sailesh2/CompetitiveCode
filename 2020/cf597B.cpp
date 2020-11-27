#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,n,r,p,s,r2,p2,s2;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>r>>p>>s;
        string seq;
        cin>>seq;
        r2=0,p2=0,s2=0;
        for(int j=0;j<n;j++){
            if(seq[j]=='R'){
                r2++;
            }else if(seq[j]=='P'){
                p2++;
            }else{
                s2++;
            }
        }
        int v=min(r,s2) + min(p,r2) + min(s,p2);
        if(v>=(n/2+n%2)){
            cout<<"YES\n";
            char al[n];
            for(int j=0;j<n;j++){
                if(seq[j]=='S' && r>0){
                    al[j]='R';
                    r--;
                }
                else if(seq[j]=='R' && p>0){
                    al[j]='P';
                    p--;
                }
                else if(seq[j]=='P' && s>0){
                    al[j]='S';
                    s--;
                }else{
                    al[j]='0';
                }
            }

            for(int j=0;j<n;j++){
                if(al[j]=='0'){
                    if(r>0){
                        al[j]='R';
                        r--;
                    }else if(p>0){
                        al[j]='P';
                        p--;
                    }else{
                        al[j]='S';
                        s--;
                    }
                }
            }
            for(int j=0;j<n;j++)
            cout<<al[j];

            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}
