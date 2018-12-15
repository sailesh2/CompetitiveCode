#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,s=0,per,id,p;
    cin>>n>>m;
    int arr[100]={0};
    for(int i=0;i<n;i++){
        cin>>id>>p;
        arr[id]=arr[id]+p;
        s=s+p;
    }
    per=s/m;
    arr[1]=arr[1]+(per*m-s);
    for(int i=1;i<=m;i++){
        cout<<i<<" "<<arr[i]-per<<"\n";
    }
    return 0;
}
