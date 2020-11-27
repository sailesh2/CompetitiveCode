#include<bits/stdc++.h>

using namespace std;
int n;
int res[100];

void clearRes(){
    for(int i=0;i<100;i++)
        res[i]=0;
}

int storeCount(int val){
    int ctr=0;
    while(val>0){
        res[ctr]=res[ctr]+val%2;
        val=val/2;
        ctr++;
    }

    return ctr;
}

int storeCount(int* arr){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,storeCount(arr[i]));
    }
    return maxi;
}

string game(int* arr){
    string gameRes[3];
    gameRes[0]="WIN";
    gameRes[1]="LOSE";
    gameRes[2]="DRAW";

    clearRes();
    int maxInd = storeCount(arr)-1;

    for(int i = maxInd;i>=0;i--){
        if(res[i]%2!=0){
            if((res[i]/2 + res[i]%2)%2!=0){
                return gameRes[0];
            }else{
                return gameRes[1-((n-res[i])%2)];
            }
        }
    }

    return gameRes[2];
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        cout<<game(arr)<<"\n";
    }
    return 0;
}
