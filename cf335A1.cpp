#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    if(a>=x && b>=y && c>=z){
        cout<<"Yes";
    } else{
        int ex=0;
        if(a>x){
            ex=ex+(a-x)/2;
        }
        if(b>y){
            ex=ex+(b-y)/2;
        }
        if(c>z){
            ex=ex+(c-z)/2;
        }
        int cnt=0;
        if(a<x){
            if(x-a<=ex){
                ex=ex-(x-a);
            }else{
                cnt=1;
            }
        }
        if(b<y){
            if(y-b<=ex){
                ex=ex-(y-b);
            }else{
                cnt=1;
            }
        }
        if(c<z){
            if(z-c<=ex){
                ex=ex-(z-c);
            }else{
                cnt=1;
            }
        }

        if(cnt==0){
            cout<<"Yes";
        } else{
            cout<<"No";
        }
    }
    return 0;
}
