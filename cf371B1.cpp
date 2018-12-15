#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n],x;
    int ctr=0;
    set<int> has;
    for(int i=0;i<n;i++){
        cin>>x;
        if(has.count(x)==0){
            has.insert(x);
            arr[ctr++]=x;
        }
    }
    if(ctr>3){
        cout<<"NO";
    } else if(ctr==3)
    {
        sort(arr,arr+ctr);
        if(arr[1]-arr[0]==arr[2]-arr[1]){
            cout<<"YES";
        } else{
            cout<<"NO";
        }

    } else{
        cout<<"YES";
    }
    return 0;
}
