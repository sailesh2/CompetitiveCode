#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

long long int lcm(long long int a ,long long int b)
{
   return (a*b)/gcd(a,b);
}
int main(){
    long long int a,b;
    cin>>a>>b;

    long long int diff=max(a,b) - min(a,b);

    if(diff==0){
        cout<<diff;
    }else{
        long long int next,mini,fac1,fac2;
        int cnt=0;
        mini=lcm(a,b);
        long long int save=0,l;
        for(long long int i=1;i*i<=diff;i++){
            if(diff%i==0){
                fac1=i;
                fac2=diff/i;

                next = (long long int)ceil((float)min(a,b)/fac1);
                next=next*fac1;

                l=lcm(next,next+diff);
                if(l<mini){
                    mini=min(mini,l);
                    save=next-min(a,b);
                }

                next = (long long int)ceil((float)min(a,b)/fac2);
                next=next*fac2;

                l=lcm(next,next+diff);
                if(l<mini){
                    mini=min(mini,l);
                    save=next-min(a,b);
                }


            }
        }

        cout<<save;
    }
    return 0;
}
