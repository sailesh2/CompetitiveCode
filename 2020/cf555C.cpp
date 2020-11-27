#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int taken=0;
    string ans="";
    for(int i=0,j=n-1;i<=j;){
        if(taken<arr[i] && taken<arr[j])
        {
            if(arr[i]<arr[j]){
                taken=arr[i];
                i++;
                ans.push_back('L');
            }else{
                taken=arr[j];
                j--;
                ans.push_back('R');
            }
        }else if(taken<arr[i]){
                taken=arr[i];
                i++;
                ans.push_back('L');

        }else if(taken<arr[j]){
                taken=arr[j];
                j--;
                ans.push_back('R');
        }else{
            break;
        }

    }
    cout<<ans.length()<<"\n";
    cout<<ans;
    return 0;
}
