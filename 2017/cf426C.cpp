#include<bits/stdc++.h>

using namespace std;

#define gc getchar

inline long long int lscan()
{
long long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
int main(){
    int n;
    cin>>n;
    long long int a,b,l,g;
    for(int i=0;i<n;i++){
        a=lscan();
        b=lscan();
        l=a*b;
        g=(long long int)ceil(cbrt(l));

        if(abs((g*g*g)-l)==0 && a%g==0 && b%g==0){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
