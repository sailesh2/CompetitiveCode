#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int dis[3][3];
    int a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    dis[0][1]=a;
    dis[1][0]=a;

    dis[0][2]=b;
    dis[2][0]=b;

    dis[1][2]=c;
    dis[2][1]=c;

    int cnt=0,ctr=0;
    for(int i=1;i<n;i++){
        if(cnt==0){
            if(dis[cnt][1]<dis[cnt][2]){
                ctr=ctr+dis[cnt][1];
                cnt=1;
            }else{
                ctr=ctr+dis[cnt][2];
                cnt=2;

            }

        } else if(cnt==1){
            if(dis[cnt][0]<dis[cnt][2]){
                ctr=ctr+dis[cnt][0];
                cnt=0;
            }else{
                ctr=ctr+dis[cnt][2];
                cnt=2;

            }
        }else{
            if(dis[cnt][0]<dis[cnt][1]){

                ctr=ctr+dis[cnt][0];
                 cnt=0;
            }else{
                ctr=ctr+dis[cnt][1];

                cnt=1;
            }
        }
    }
    cout<<ctr;
    return 0;
}
