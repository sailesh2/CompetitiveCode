#include<bits/stdc++.h>

using namespace std;
long long int maxPower = 450;
long long int powval[450][2];

void setup(){
    for(long long int i=0;i<maxPower;i++){
        powval[i][0]=0;
        powval[i][1]=0;
    }
}

void store(long long int base, long long int raise){
    /*if(powval[base][0]==-1){
        powval[base][0]=raise;
    }
    else if(powval[base][1]==-1){
        if(raise<powval[base][0]){
            powval[base][1]=powval[base][0];
            powval[base][0]=raise;
        }else
            powval[base][1]=raise;
    }
    else */if(raise<powval[base][0]){
        powval[base][1]=powval[base][0];
        powval[base][0]=raise;
    }
    else if(raise<powval[base][1]){
        powval[base][1]=raise;
    }
}

void storeInit(long long int base, long long int raise, long long int index){
    if(index==0){
        powval[base][1]=raise;
    }else{
        if(raise<powval[base][1]){
            powval[base][0]=raise;
        }
        else{
            powval[base][0]=powval[base][1];
            powval[base][1]=raise;
        }
    }
}

void storePower(long long int n){

    long long int ctr=0;
    while(n%2==0){
        ctr++;
        n=n/2;
    }

    if(ctr>0){
        mp[2]++;
    }
    store(2,ctr);

    for(long long int i=3;i*i<=n;i=i+2){

        ctr=0;
        while(n%i==0){
            ctr++;
            n=n/i;
        }


        if(ctr>0){
            mp[i]++;
        }
        store(i,ctr);
    }

    if(n>2){
        mp[n]++
        store(n,1);
    }
}

void storeInitPower(long long int n, long long int index){

    long long int ctr=0;
    while(n%2==0){
        ctr++;
        n=n/2;
    }

    storeInit(2,ctr,index);

    for(long long int i=3;i*i<=n;i=i+2){

        ctr=0;
        while(n%i==0){
            ctr++;
            n=n/i;
        }

        storeInit(i,ctr,index);
    }

    if(n>2){
        storeInit(n,1,index);
    }
}

long long int fastPow(long long int a, long long int b){
    long long int bin=a,p=1;
    while(b>0){
        if(b%2==1){
            p=(p*bin);
        }
        bin=(bin*bin);
        b=b/2;
    }
    return p;
}

int main(){
    long long int n,x;
    cin>>n;

    setup();
    for(long long int i=0;i<n;i++){
        cin>>x;
        if(i>=2)
        storePower(x);
        else
        storeInitPower(x,i);
    }
    long long int p=1;
    for(long long int i=1;i<maxPower;i++){
        //if(powval[i][1]!=-1)
        p=p*fastPow(i,powval[i][1]);
    }
    cout<<p;
    return 0;
}
