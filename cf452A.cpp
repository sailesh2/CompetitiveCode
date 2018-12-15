#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int one=0,two=0,x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x==1)
            one++;
        else
            two++;
    }
    cout<<min(one,two)+(one-(min(one,two)))/3;
    return 0;
}
