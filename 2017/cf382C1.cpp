#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

long long int fun(long long int);

int main(){
    long long int n;
    cin>>n;
    cout<<fun(n);
    return 0;
}

long long int fun(long long int n){
    if(n==1)
        return 0;
    return fun(n/2)+n%2+1;
}
