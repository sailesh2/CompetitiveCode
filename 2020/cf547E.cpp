#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int h,n;
    cin>>h>>n;
    long long int hitPoints[n];
    for(long long int i=0;i<n;i++){
        cin>>hitPoints[i];
    }

    long long int cnt=0;
    long long int start=h;
    for(long long int i=0;i<n;i++){
        h=h+hitPoints[i];
        if(h<0){
            cnt=i+1;
            break;
        }
    }

    if(cnt>0){
        cout<<cnt;
    }else{
        if(h>=start){
            cout<<"-1";
        }else{
            long long int diff=start-h;
            long long int times=(start/diff)*n;
            long long int rem=start%diff;
            for(long long int i=0;i<n;i++){
                rem=rem+hitPoints[i];
                if(rem<0){
                    times=times+i+1;
                    break;
                }
            }
            cout<<times;
        }
    }
    return 0;
}
