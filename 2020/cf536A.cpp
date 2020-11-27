#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cross=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='X' && (i-1>=0 && j-1>=0 && arr[i-1][j-1]== 'X') &&
               (i+1<n && j+1<n && arr[i+1][j+1]== 'X') &&
               (i-1>=0 && j+1<n && arr[i-1][j+1]== 'X') &&
               (i+1<n && j-1>=0 && arr[i+1][j-1]== 'X')){
                cross++;
               }
        }
    }
    cout<<cross;
    return 0;
}
