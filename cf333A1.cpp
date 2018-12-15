#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,bx,y,by;
    cin>>n>>bx;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>y>>by;
    int brr[y];
    for(int i=0;i<y;i++){
        cin>>brr[i];
    }

    long long int dx=0,px=1;
    for(int i=n-1;i>=0;i--){

        dx=dx+arr[i]*px;
        px=px*bx;
    }

    long long int dy=0,py=1;
    for(int i=y-1;i>=0;i--){

        dy=dy+brr[i]*py;
        py=py*by;
    }

    if(dx==dy){
        cout<<"=";
    } else if(dx<dy){
        cout<<"<";
    } else{
        cout<<">";
    }
}
