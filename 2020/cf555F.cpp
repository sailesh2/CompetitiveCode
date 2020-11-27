#include<bits/stdc++.h>

using namespace std;
long long int n,k;

bool isPossible(long long int num){
  long long int s=((k+num)*(k+num-1))/2 - (num*(num-1))/2;
  return s<=n;
}

long long int binSearWithSteps(){
    long long int ctr=1;
    long long int save=0;
    long long int save2=0;

    while(1){
        while(save+ctr<=n && isPossible(save+ctr)){
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
    cin>>n>>k;

    long long int arr[k];
    long long int save=-1;
    save=binSearWithSteps();
    if(save==0){
        cout<<"NO";
    }else{
        long long int s=0;
        for(long long int i=save;i<save+k;i++){
            arr[i-save]=i;
            s=s+arr[i-save];
        }

        long long int d = n-s;
        for(long long int i=k-1;i>=0;i--){
            if(d==0){
                break;
            }
            long long int old=arr[i];

            arr[i]=arr[i]+d;
            s=s+d;
            if(i-1>=0 && arr[i]>arr[i-1]*2){
                arr[i]=arr[i-1]*2;
                s=s-d;
                s=s+arr[i]-old;
            }
            if(i+1<k && arr[i]==arr[i+1]){
                break;
            }
            d=n-s;
        }
        if(d!=0){
            cout<<"NO";
        }else{
            cout<<"YES\n";
            for(long long int i=0;i<k;i++){
                cout<<arr[i]<<" ";
            }
        }
    }
    return 0;
}
