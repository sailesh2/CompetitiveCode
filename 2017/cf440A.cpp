#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,m,x,mini1=10,mini2=10;
    cin>>n>>m;
    int arr[10]={0};
    int brr[m];
    int mini3=10;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[x]=1;
        mini1=min(mini1,x);
    }

    for(int i=0;i<m;i++){
        cin>>x;
        brr[i]=x;
        mini2=min(mini2,x);
    }
    for(int i=0;i<m;i++){
        if(arr[brr[i]]==1){
            mini3=min(mini3,brr[i]);
        }
    }

    if(mini3<10){
        cout<<mini3;
    }else{
        cout<<(min(mini1,mini2))*10+max(mini1,mini2);
    }

    return 0;
}
