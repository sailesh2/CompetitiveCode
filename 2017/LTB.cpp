#include<bits/stdc++.h>

using namespace std;

string maxDiv6(long long int n){
    vector<int> dig;
    int k=0;
    while(n>0){
        dig.push_back(n%10);
        n=n/10;
        k++;
    }
    long long int p=1,sm=0;
    long long int left[k];
    for(int i=0;i<k;i++){
        sm=sm+(dig[i])*p;
        left[i]=sm;
        p=p*10;
    }
    p=p/10;
    sm=0;
    long long int right[k];

    for(int i=k-1;i>=0;i--){
        sm=sm+(dig[i])*p;
        right[i]=sm;
        p=p/10;
    }

    long long int l,r,maxi=-1,save=-1;
    for(int i=0;i<k;i++){
        if(i-1<0)
            l=0;
        else
            l=left[i-1];
        if(i+1>=k)
            r=0;
        else
            r=right[i+1];
        sm=l+r;
        if(sm%6==0){
            if(sm>maxi){
                maxi=sm;
                save=i;
            }
        }
    }
    if(save==-1){
        return "-1";
    }else{
        string s="";
        for(int i=k-1;i>=0;i--){
            if(save!=i){
                s=s+(char)(dig[i]+'0');
            }
        }
        return s;
    }
}

int main(){
    int t;
    long long int n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cout<<maxDiv6(n)<<"\n";
    }
    return 0;
}
