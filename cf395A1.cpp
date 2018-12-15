#include<stdio.h>
#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<algorithm>

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

using namespace std;

int main(){
    int n,m,z;
    cin>>n>>m>>z;
    int lcm = (n*m)/gcd(n,m);
    cout<<z/lcm;
    return 0;
}
