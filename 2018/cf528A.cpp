#include<bits/stdc++.h>

using namespace std;

int main(){
    string t;
    cin>>t;
    int n=t.length();
    char ch[n];
    int i=0,j=n-1;
    int ctr=n-1;
    while(i<=j){
        if(i==j){
            ch[ctr--]=t[i];
            break;
        }
        if(n%2!=0){
            ch[ctr--]=t[i];
            ch[ctr--]=t[j];
        }else{
            ch[ctr--]=t[j];
            ch[ctr--]=t[i];
        }
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        cout<<ch[i];
    }
    return 0;
}
