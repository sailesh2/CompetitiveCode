#include<bits/stdc++.h>

using namespace std;

int main(){
    int c1,c2;
    cin>>c1>>c2;
    int ctr=0;
    while(1){

        if(c1<=0 || c2<=0){
            break;
        }

        if(c1==c2 && c1==1){
            break;
        }
        if(c1<=c2){
            c1=c1+1;
            c2=c2-2;
        } else if(c1>c2){
            c1=c1-2;
            c2=c2+1;
        }
        ctr++;
    }
    cout<<ctr;
    return 0;
}
