#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int t,l,r,m;
    long long int a,b,c;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>l>>r>>m;

        for(long long int j=l;j<=r;j++){
            long long int d = m/j;
            long long int rem = m%j;
            if(d>0LL){
                if(rem<=(r-l)){
                    a=j;
                    b=l+rem;
                    c=l;
                    break;
                }
                d++;
                rem=m-d*j;
                if(abs(rem)<=(r-l)){
                    a=j;
                    b=l;
                    c=l+abs(rem);
                    break;
                }
            }else{
                rem=m-j;
                if(abs(rem)<=(r-l)){
                    a=j;
                    b=l;
                    c=l+abs(rem);
                }
                break;
            }
        }


        cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    return 0;
}
