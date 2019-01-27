#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin>>x;
    int cnt=0,a,b;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
                if((i%j)==0 && (i*j)>x && (i/j)<x){
                    cnt=1;
                    a=i;
                    b=j;
                    break;
                }

        }
        if(cnt==1)
            break;
    }
    if(cnt==0)
        cout<<"-1";
    else
        cout<<a<<" "<<b;
    return 0;
}
