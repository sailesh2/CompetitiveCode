#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    long long int left[n],right[n];
    pair<long long int, pair<long long int, long long> > leftStk[n],rightStk[n];
    long long int maxi,mini;
    long long int top=-1,ctr,prev;
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
        ctr=0LL;
        while(top>-1 && leftStk[top].first>arr[i]){
            ctr=ctr+leftStk[top].second.second;
            top--;
        }
        prev=top>-1?leftStk[top].second.first:0LL;
        top++;
        leftStk[top]=make_pair(arr[i],make_pair(((ctr+1)*arr[i])+prev,ctr+1));
        left[i]=leftStk[top].second.first;
    }

    top=-1;
    for(long long int i=n-1;i>=0;i--){
        ctr=0LL;
        while(top>-1 && rightStk[top].first>arr[i]){
            ctr=ctr+rightStk[top].second.second;
            top--;
        }
        prev=top>-1?rightStk[top].second.first:0LL;
        top++;
        rightStk[top]=make_pair(arr[i],make_pair(((ctr+1)*arr[i])+prev,ctr+1));
        right[i]=rightStk[top].second.first;
    }

    maxi=0LL;
    long long int save=-1;
    for(long long int i=0;i<n-1;i++){
        if((left[i]+right[i+1])>maxi){
            maxi=left[i]+right[i+1];
            save=i;
        }
    }

    if(left[n-1]>maxi){
        maxi=left[n-1];
        save=n-1;
    }
    if(right[0]>maxi){
        maxi=right[0];
        save=-1;
    }

    vector<long long int> leftAns, rightAns;
    for(long long int i=save;i>=0;i--){
        if(i==save){
            mini=arr[i];
        }else{
            mini=min(mini,arr[i]);
        }
        leftAns.push_back(mini);
    }

    for(long long int i=save+1;i<n;i++){
        if(i==save+1){
            mini=arr[i];
        }else{
            mini=min(mini,arr[i]);
        }
        rightAns.push_back(mini);
    }

    long long int l= leftAns.size();
    l--;
    for(long long int i=l;i>=0;i--)
        cout<<leftAns[i]<<" ";
    for(long long int i=0;i<rightAns.size();i++)
        cout<<rightAns[i]<<" ";
    return 0;
}
