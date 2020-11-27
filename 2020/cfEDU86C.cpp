#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

long long int lcm(long long int a , long long int b)
{
   return (a*b)/gcd(a,b);
}

int main(){
    long long int t,a,b,l,r,q;
    cin>>t;
    for(long long int i=0;i<t;i++){
        cin>>a>>b>>q;
        long long int tempa = a;
        long long int tempb = b;
        a=min(tempa,tempb);
        b=max(tempa,tempb);


        long long int lm = lcm(a,b);

        for(long long int j=0;j<q;j++){
            cin>>l>>r;
            l=max(l,b);
            long long int ans=0;
            if(l<=r){
                if(lm==b){
                    b--;
                }
                    ans = (r-l+1) - (b)*(r/lm - (l-1)/lm);

                    long long int first = ((l-1)/lm)*lm;
                    if(first>0)
                        ans = ans + max(0LL,(first + b - l + 1));

                    long long int last = (r/lm)*lm;
                    if(last>0)
                        ans = ans - max(0LL,(last + b - r));

            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
