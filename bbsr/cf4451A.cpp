#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int save=-1,ctr=10000000;
    for(int i=0;i<=10;i++){
        if(n-i>=0 && (n-i)%10==0){
            save=n-i;
            ctr=i;
            break;
        }
    }

    int save2=-1,ctr2=10000000;
    for(int i=0;i<=10;i++){
        if((n+i)%10==0){
            save2=n+i;
            ctr2=i;
            break;
        }
    }

    if(ctr<ctr2){
        cout<<save;
    }else{
        cout<<save2;
    }
    return 0;
}
