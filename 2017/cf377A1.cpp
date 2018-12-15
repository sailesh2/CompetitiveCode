#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int k,r,i;
    cin>>k>>r;
    for(i=1;i<=10;i++){
        if((k*i)%10==r || (k*i)%10==0)
            break;
    }
    cout<<i;
    return 0;
}
