#include<bits/stdc++.h>

using namespace std;

long long int p[100005];

void buildP(){

    for(long long int i=1;i<=100005;i++){
        p[i-1]=(i*(3*i+1))/2;
    }
}


long long int bin(long long int cost){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<100005 && p[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save;
}



long long int pyramids(long long int n){


    long long int ans=0;
    while(n>0){
        long long int index=bin(n);

        if(index>=0){
            ans++;
            n=n-p[index];
        }
        else
        break;
    }

    return ans;
}

int main(){
    long long int t,n;
    cin>>t;
    buildP();
    for(long long int i=0;i<t;i++){
        cin>>n;
        cout<<pyramids(n)<<"\n";
    }
    return 0;
}
