#include<bits/stdc++.h>

using namespace std;

long long int h,n;
long long int loss=0;

long long int getRemainingHealth(long long int days){
    return h+days*loss;
}

bool canDie(long long int days, long long int* hitPoints){
    long long int rem=getRemainingHealth(days);
    //cout<<days<<" "<<rem<<"\n";
    if(rem<=0)
        return true;
    for(long long int i=0;i<n;i++){
        rem=rem+hitPoints[i];
        if(rem<=0)
            return true;
    }
    return false;
}

long long int binSear(long long int* hitpoints){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(!canDie(save+ctr,hitpoints)){
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


int main(){
    cin>>h>>n;
    long long int hitPoints[n];
    long long int ht=h;
    bool possible=false;
    for(long long int i=0;i<n;i++){
        cin>>hitPoints[i];
        ht=ht+hitPoints[i];
        if(ht<=0){
            possible=true;
        }
        loss=loss+hitPoints[i];
    }

    if(loss>=0 && !possible){
        cout<<"-1";
    }else{
        long long int days = binSear(hitPoints);
        days++;
        long long int rem=getRemainingHealth(days);
        if(rem<=0){
            cout<<days*n;
        }else{
        for(int i=0;i<n;i++){
            rem=rem+hitPoints[i];
            if(rem<=0){
                cout<<i+1+days*n;
                break;
            }
        }
        }
    }
    return 0;
}
