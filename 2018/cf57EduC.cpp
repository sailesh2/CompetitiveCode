#include<bits/stdc++.h>

using namespace std;

int minAngle(int x){
    int p,q,maxA;
    bool div1,div2;
    for(int n=3;n<=180;n++){
         maxA = (180*(n-2))/n;
        for(int t=1;t<=n-2;t++){
            p=((180*(n+t+3)*(n-2))/n - 180*(n-2-t) - 2*x)/2;
            div1= (180*(n+t+3)*(n-2))%n==0 && ((180*(n+t+3)*(n-2))/n - 180*(n-2-t) - 2*x)%2==0;
            q=(t*360)/n - x - p;
            div2= (t*360)%n==0;

            if(div1 && div2 && p>0 && p<maxA && q>0 && q<maxA)
                return n;
        }
    }
    return -1;
}


int main(){
    int t;
    cin>>t;
    int x;
    for(int i=0;i<t;i++){
        cin>>x;
        cout<<minAngle(x)<<"\n";
    }
    return 0;
}
