#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<math.h>

using namespace std;

bool fun(int a,int b){
    return a>b;
}

int main(){
    int n,k,a;
    cin>>n>>k;
    double s =0;
    for(int i=0;i<n;i++){
        cin>>a;
        s= s+ceil((double)a/k);
    }
    cout<<(long long int)(ceil(s/2));
    return 0;
}
