#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxA[n];
    vector<int> v;
    for(int i=0;i<n-1;i++){
        if(i==0)
            maxA[i]=arr[i];
        else
            maxA[i]=max(arr[i],maxA[i-1]);
        if(arr[i+1]<arr[i]){
            v.push_back(i);
            v.push_back(i+1);
        }
    }
    v.push_back(n-1);
    int ctr,maxi=-1,save=-1,st;
    for(int i=0;i<v.size();i++){
        st=v[i];
        ctr=0;
        if(st-1==-1 || arr[st]>maxA[st-1]){
            ctr--;
        }

        for(int j=st+1;j<n-1;j++){
            if(arr[j]<arr[j+1]){
                if(st-1==-1 || arr[j]>maxA[st-1]){
                    if(arr[j]>arr[st])
                        break;
                    else
                        ctr++;
                }
            }else{
                if(arr[j]<arr[st] && (st-1==-1 || arr[j]>maxA[st-1]))
                    ctr++;
                break;
            }
        }
        if(ctr>maxi){
            maxi=ctr;
            save=st;
        }else if(ctr==maxi){
            if(arr[st]<arr[save]){
                save=st;
            }
        }
    }
    cout<<arr[save];
    return 0;
}
