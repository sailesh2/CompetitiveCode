#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[500]={0};
    char ch;
    int cnt=0;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        ch=s[i];
        arr[(int)ch]++;
    }
    for(int i='a';i<='z';i++){
        if(arr[i]>k){
            cnt=1;
            break;
        }
    }

    if(cnt==1){
        cout<<"NO";
    } else{
        cout<<"YES";
    }
    return 0;
}
