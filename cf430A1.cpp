#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int l,r,x,y,k,cnt=0;
    cin>>l>>r>>x>>y>>k;
    for(int i=l;i<=r;i++){
        if(i%k==0){
            if(i/k>=x && i/k<=y){
                cnt=1;
                break;
            }
        }
    }
    if(cnt==1){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
    return 0;
}
