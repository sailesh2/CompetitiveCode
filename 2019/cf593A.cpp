#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int a,b,c;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        int s=0;
        if(c>=2 && b>=1){
            if(b>=c/2){
                s=s+c/2+2*(c/2);
                b=b-c/2;
            }else{
                s=s+b+2*b;
                b=0;
            }
        }
        if(b>=2 && a>=1){
            if(a>=b/2){
                s=s+b/2+2*(b/2);
                a=a-b/2;
            }else{
                s=s+a+2*a;
                a=0;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
