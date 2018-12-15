#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> mset;
    int maxi1,maxi2;
    int mini1,mini2;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        arr[i][0]=l;
        arr[i][1]=r;
        if(l>maxi1){
            maxi2=maxi1;
            maxi1=l;
        }else if(l==maxi1){
            maxi2=l;
        }else{
            if(l>maxi2){
                maxi2=l;
            }
        }


        if(>maxi1){
            maxi2=maxi1;
            maxi1=l;
        }else if(l==maxi1){
            maxi2=l;
        }else{
            if(l>maxi2){
                maxi2=l;
            }
        }
    }

    for(int i=0;i<m;i++){
        l=arr[i][0];
        r=arr[i][1];

        mset.erase(l);
        mset.erase(r);
    }
    return 0;
}
