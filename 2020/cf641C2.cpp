#include<bits/stdc++.h>

using namespace std;
long long int maxPower = 200005;
long long int powval[200005][2];

long long int powerst[200005]={0};
vector<long long int> powers;

void setup(){
    for(long long int i=0;i<maxPower;i++){
        powval[i][0]=0;
        powval[i][1]=0;
    }
}

void store(long long int base, long long int raise){
    if(raise<powval[base][0]){
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
        if(powerst[2]==0){
            storeInit(2,ctr,0);
            powers.push_back(2);
        }else if(powerst[2]==1){
            storeInit(2,ctr,1);
        }else{
            store(2,ctr);
        }
        powerst[2]++;
    }

    for(long long int i=3;i*i<=n;i=i+2){

        ctr=0;
        while(n%i==0){
            ctr++;
            n=n/i;
        }


        if(ctr>0){
            if(powerst[i]==0){
                storeInit(i,ctr,0);
                powers.push_back(i);
            }else if(powerst[i]==1){
                storeInit(i,ctr,1);
            }else{
                store(i,ctr);
            }

            powerst[i]++;
        }
    }

    if(n>2){
                if(powerst[n]==0){
                    storeInit(n,1,0);
                    powers.push_back(n);
                }else if(powerst[n]==1){
                    storeInit(n,1,1);
                }else{
                    store(n,1);
                }

                powerst[n]++;

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
        storePower(x);
    }

    long long int p=1;

    for(long long int j=0;j<powers.size();j++){
        long long int po = powers[j];
        if(powerst[po]==n){
            p=p*fastPow(po,powval[po][1]);
        }else if(powerst[po]==n-1){
            if(powerst[po]==1){
                p=p*fastPow(po,powval[po][1]);
            }else{
                p=p*fastPow(po,powval[po][0]);
            }
        }
    }
    cout<<p;
    return 0;
}
