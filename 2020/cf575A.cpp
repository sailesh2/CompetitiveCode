#include<bits/stdc++.h>

using namespace std;

long long int dist(long long int a,long long int b,long long int c){

    long long int maxi=0;

    long long int x=(b+c-a)/2;

    maxi=max(maxi,min(a+x,b+c-x));
    maxi=max(maxi,min(a+c-x,b+x));

    x++;

    maxi=max(maxi,min(a+x,b+c-x));
    maxi=max(maxi,min(a+c-x,b+x));
    return maxi;

}

int main(){
    int q;
    long long int a,b,c;

    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>c;
        long long int maxi=0;
        maxi=max(maxi,dist(a,b,c));
        maxi=max(maxi,dist(a,c,b));
        maxi=max(maxi,dist(c,b,a));
        cout<<maxi<<"\n";
    }
    return 0;
}
