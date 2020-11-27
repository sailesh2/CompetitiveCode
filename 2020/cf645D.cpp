#include<bits/stdc++.h>

using namespace std;

long long int calSum(long long int first, long long int last, long long int* dsum){
    if(first>0)
    return dsum[last]-dsum[first-1];
    else
    return dsum[last];
}

bool isPossible(long long int first, long long int last, long long int* dsum, long long int x){
    long long int dx = calSum(first, last, dsum);
    return dx<=x;
}

long long int getHugs(long long int index, long long int* d, long long int* sum, long long int* dsum, long long int x){
    long long int ctr=1;
    long long int save=-1;
    long long int save2=-1;

    while(1){
        while(save+ctr<=index && isPossible(index-(save+ctr), index, dsum, x)){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    long long int hugs = 0;
    long long int daysTaken = x;
    if(save>=0){
        hugs = hugs + calSum(index-save, index, sum);
        daysTaken = daysTaken - calSum(index-save, index, dsum);
    }

    if(daysTaken>0){
        long long int first = index - (save+1);
        long long int remd=d[first]-daysTaken;
        long long int remSum = (remd*(remd+1))/2;
        long long int totSum = (d[first]*(d[first]+1))/2;
        hugs = hugs + totSum - remSum;
    }

    return hugs;
}

int main(){
    long long int n,x;
    cin>>n>>x;
    long long int d[2*n];
    for(long long int i=0;i<n;i++){
        cin>>d[i];
    }
    for(long long int i=n;i<2*n;i++){
        d[i]=d[i-n];
    }

    long long int sum[2*n];
    long long int s=0;
    for(long long int i=0;i<2*n;i++){
        s=s+(d[i]*(d[i]+1))/2;
        sum[i]=s;
    }

    long long int dsum[2*n];
    s=0;
    for(long long int i=0;i<2*n;i++){
        s=s+d[i];
        dsum[i]=s;
    }

    long long int maxi=0;
    for(long long int i=n;i<2*n;i++){
        long long int hugs = getHugs(i,d,sum,dsum,x);
        maxi=max(maxi,hugs);
    }
    cout<<maxi;
    return 0;
}
