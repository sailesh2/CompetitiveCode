#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int a,b,c,d;
    cin>>a>>b>>c>>d;

    long long int ans=0;
    for(long long int i=a;i<=b;i++){

        long long int y=d-i;
        long long int c2;
        if(y>=b && y<=c){
            ans=ans+(c-y)*(d-c+1);
            c2=y;
        }else{
            c2=c;
        }

        long long int l = i+c2;

        long long int r = min(l-1,d);
        long long int nos = r-c+1;
        if(nos>0){
            long long int terms = c2-b+1;
            long long int extra = ((nos-terms)>=0)?(((nos-terms)*(nos-terms+1))/2):0LL;
            ans=ans+(nos*(nos+1))/2 - extra;
        }
    }
    cout<<ans;
    return 0;
}
