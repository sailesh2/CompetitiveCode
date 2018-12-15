#include<bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin>>c;
    int f=(int)(floor((float)(9*c+(32*5))/5));
    int f2=(int)(ceil((float)(9*c+(32*5))/5));

    float c1=(float)(5*(f-32))/9;
    float c2=(float)(5*(f2-32))/9;

    if(c1<=c){
        cout<<f;
    }else{
        cout<<f2;
    }
    return 0;
}
