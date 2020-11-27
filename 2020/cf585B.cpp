#include<bits/stdc++.h>

using namespace std;

long long int getSum(vector<long long int> arr){

    long long int s=0,start=0,done=1,cnt=0,ctrL=0,ctrR=0;
    long long int ctr=0,save=0,save2=-1;
    long long int n=arr.size();
    for(long long int i=0;i<n;i++){
        if(arr[i]<0){
            cnt=1-cnt;
        }
        if(cnt==1){
            ctrR++;
            if(done==1){
            save=save+i-save2;
            done=0;
            }
        }else{
            if(done==0){
                save2=i;
                s=s+save*ctrR;
                done=1;
            }
            ctrR=0;
        }
    }
    if(cnt==1){
        s=s+save*ctrR;
    }
    return s;
}
long long int getOddSum(vector<long long int> brr){
    vector<long long int> v;
    long long int n = brr.size();

    long long int save=n;
    for(long long int i=0;i<n;i++){
        if(brr[i]<0){
            save=i;
            break;
        }
    }

    for(long long int i=save+1;i<n;i++){
        v.push_back(brr[i]);
    }

    return getSum(v);
}
int main(){
    long long int m;
    cin>>m;
    long long int x;
    vector<long long int> arr;
    for(long long int i=0;i<m;i++){
        cin>>x;
        arr.push_back(x);
    }
    long long int s=getSum(arr);
    s=s+getOddSum(arr);
    long long int tot=(m*(m+1))/2;
    cout<<s<<" "<<tot-s;
    return 0;
}
