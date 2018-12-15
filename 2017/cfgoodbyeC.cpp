#include<bits/stdc++.h>

using namespace std;
int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int k,pa,pb;

pair<int,int> expected(int a,int sm){
    if(sm>=k)
        return make_pair(1,1);

    int sm1=sm+(a+1);
    pair<int,int> p=expected(a+1,sm1);
    int v=pa*p.first;
    int d=(pa+pb)*p.second;

    sm1=sm+a;
    p=expected(a,sm1);
    int l=lcm(d,(pa+pb)*p.second);

    int n=v*(l/d)+pb*p.first*(l/((pa+pb)*p.second));
    return make_pair(n,l);
}
int main(){
    cin>>k>>pa>>pb;
    pair<int,int> p=expected(0,0);
    cout<<p.first<<" "<<p.second;
    return 0;
}
