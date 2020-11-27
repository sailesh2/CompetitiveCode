#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n,x,y;
        cin>>n;
        int minX=-100000,maxX=100000,minY=-100000,maxY=100000;
        int f1,f2,f3,f4;
        for(int i=0;i<n;i++){
            cin>>x>>y>>f1>>f2>>f3>>f4;
            if(f1==0){
                minX=max(minX,x);
            }
            if(f2==0){
                maxY=min(maxY,y);
            }
            if(f3==0){
                maxX=min(maxX,x);
            }
            if(f4==0){
                minY=max(minY,y);
            }

        }

        if(maxX<minX || maxY<minY){
            cout<<"0\n";
        }else{
            cout<<"1 "<<maxX<<" "<<maxY<<"\n";
        }
    }
    return 0;
}
