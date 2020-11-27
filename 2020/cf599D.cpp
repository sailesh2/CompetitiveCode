#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a , long long int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int main(){
    long long int n;
    cin>>n;
    long long int mini=n;
    vector<long long int> v;
    v.push_back(0);
    for(long long int i=1;i*i<=n;i++){
        if(n%i==0){
            long long int one=i;
            long long int two=n/i;

            if(one!=two){
                if(one!=1)
                v.push_back(one);
                if(two!=1)
                v.push_back(two);
            }else{
                if(one!=1)
                    v.push_back(one);
            }
        }
    }
    sort(v.begin(),v.end());
    for(long long int i=0;i<v.size();i++){
        mini=gcd(mini,v[i]);
    }
    cout<<mini;
    return 0;
}
