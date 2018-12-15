#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int fun(int,int);
int save[100000][2];
int arr[100000];
int n;
int main(){
    int i,t,j,a,b;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        for(j=0;j<n;j++){
            save[j][0]=0;
            save[j][1]=0;
            cin>>arr[j];
        }
        a=fun(1,1);
        b=fun(0,1);
        if(a>=b)
            cout<<a<<"\n";
        else
            cout<<b<<"\n";
    }
    return 0;
}



int fun(int p,int i){
    int a,b;
    if(i>=n)
        return 0;
    if(save[i+1][1]!=0)
        a=save[i+1][1];
    else
        a=fun(1,i+1);
    if(p==1)
        a=a+abs(arr[i]-arr[i-1]);
    else
        a=a+abs(arr[i]-1);
    if(save[i+1][0]!=0)
        b=save[i+1][0];
    else
        b=fun(0,i+1);
    if(p==1)
        b=b+abs(arr[i-1]-1);
    if(a>=b)
        save[i][p]=a;
    else
        save[i][p]=b;
    return save[i][p];
}
