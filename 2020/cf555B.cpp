#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string digs;
    cin>>digs;
    int funMap[10];

    for(int i=0;i<9;i++){
        cin>>funMap[i+1];
    }


    int cnt=0;
    int d;
    int start=n,endi=0;
    for(int i=0;i<n;i++){
        d=(int)digs[i]-48;

        if(cnt==0){
            if(funMap[d]>d){
                cnt=1;

                start=i;
                endi=i;
            }
        }else{
            if(funMap[d]<d){
                break;
            }
            endi=i;
        }
    }
    int nm=0;

    for(int i=start;i<=endi;i++){
        d=(int)digs[i]-48;

        digs[i]=(char)(funMap[d]+48);
    }

    for(int i=0;i<n;i++){
        cout<<digs[i];
    }

    return 0;

}
