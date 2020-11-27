#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int pos=0,neg=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>0)
            pos++;
        if(arr[i]<0)
            neg++;
    }
    int h=(int)ceil(float(n)/2);
    if(pos>=h)
        cout<<"1";
    else if(neg>=h)
        cout<<"-1";
    else
        cout<<"0";
    return 0;
}
