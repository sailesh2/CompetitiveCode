#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int left=0,right=0;
    cin>>n;
    int doors[n];
    for(int i=0;i<n;i++){
        cin>>doors[i];
        if(doors[i]==0)
            left++;
        else
            right++;
    }
    int l=0,r=0;
    for(int i=0;i<n;i++){
        if(doors[i]==0){
            l++;
        }else{
            r++;
        }
        if(l==left || r==right){
            cout<<i+1;
            break;
        }
    }

    return 0;
}
