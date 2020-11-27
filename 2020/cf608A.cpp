#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    int sum=0;
    int left;
    if(e>=f){
        left=min(a,d);
        a=a-left;
        d=d-left;
        sum=left*e;

        left=min(b,min(c,d));
        sum=sum+left*f;
    }else{
        left=min(b,min(c,d));
        d=d-left;
        sum=left*f;

        left=min(a,d);
        sum=sum+left*e;

    }
    cout<<sum;
    return 0;
}
