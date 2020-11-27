#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    string answers[n];
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        answers[i]=s;
    }
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int sm=0;
    for(int i=0;i<m;i++){
        int marks[5]={0};
        int maxi=0;
        for(int j=0;j<n;j++){
            marks[answers[j][i] - 'A']++;
        }

        for(int j=0;j<5;j++){
            maxi=max(maxi,marks[j]);
        }
        sm=sm+maxi*arr[i];
    }
    cout<<sm;
    return 0;
}
