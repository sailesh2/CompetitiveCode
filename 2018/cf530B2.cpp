#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int x=1,y=1;
    while(x*y<n){
        if(x<y)
            x++;
        else
            y++;
    }
    cout<<x+y;
    return 0;
}
