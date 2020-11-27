#include<bits/stdc++.h>

using namespace std;

int findLast(int cost, int* pc2, int k){
    int ctr=1;
    int save=-1;
    int save2=-1;

    while(1){
        while(save+ctr<k && pc2[save+ctr]<=cost){
            save2=save+ctr;
            ctr=ctr*2;
        }
        if(save==save2){
            break;
        }
        save=save2;
        ctr=1;
    }
    return save+ctr;
}

int lis(vector<int> v){
    int n=v.size();
    int top[n];
    int maxi=-1;
    for(int i=0;i<n;i++){
        int index=findLast(v[i],top,maxi+1);
        top[index]=v[i];
        maxi=max(maxi,index);
    }
    return n-(maxi+1);
}

int main(){
    int k1,k2,k3;
    cin>>k1>>k2>>k3;
    int arr1[k1];
    int arr2[k2];
    int arr3[k3];
    for(int i=0;i<k1;i++)
        cin>>arr1[i];
    for(int i=0;i<k2;i++)
        cin>>arr2[i];
    for(int i=0;i<k3;i++)
        cin>>arr3[i];

    sort(arr1,arr1+k1);
    sort(arr2,arr2+k2);
    sort(arr3,arr3+k3);

    vector<int> v;
    for(int i=0;i<k1;i++)
        v.push_back(arr1[i]);
    for(int i=0;i<k2;i++)
        v.push_back(arr2[i]);
    for(int i=0;i<k3;i++)
        v.push_back(arr3[i]);

    cout<<lis(v);
    return 0;
}
