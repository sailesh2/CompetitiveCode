#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

#define gc getchar
using namespace std;

inline long int lscan()
{
long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

int main(){
    int n;
    n=lscan();
    int arr;
    long long int sm=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        arr=lscan();
        sm=sm+arr;
        if(arr%2!=0){
            cnt=1;
        }
    }

    if(sm%2!=0){
        printf("First");
    } else{
        if(cnt==1){
            printf("First");
        }else{
            printf("Second");
        }
    }
    return 0;
}
